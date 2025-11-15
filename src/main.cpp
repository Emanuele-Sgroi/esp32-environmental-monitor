#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include "display.h"
#include "actuators.h"
#include "logic.h"

// Global variables
float temperature = 0.0;
float humidity = 0.0;
int pirDetections = 0;
int visitCount = 0;
bool tagDetected = false;
bool motionDetected = false;
bool previousMotionState = false;
int currentFanSpeed = 0;

// Timing variables
unsigned long lastTempHumidityRead = 0;
unsigned long lastMotionDetectionTime = 0;

void setup()
{
    // Initialize serial
    Serial.begin(115200);
    Serial.println("Starting...");

    // Initialize all modules
    initSensors();
    initDisplay();
    initActuators();

    // Show startup message
    showStartupMessage();

    Serial.println("System ready!");
}

void loop()
{
    unsigned long currentMillis = millis();

    // Read temperature and humidity every 2 minutes
    if (currentMillis - lastTempHumidityRead >= TEMP_HUMIDITY_INTERVAL)
    {
        readTempHumidity(temperature, humidity);
        lastTempHumidityRead = currentMillis;

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print("°C, Humidity: ");
        Serial.print(humidity);
        Serial.println("%");
    }

    // Check for motion detection
    motionDetected = isMotionDetected();

    // If motion just detected (transition from LOW to HIGH)
    if (motionDetected && !previousMotionState &&
        (currentMillis - lastMotionDetectionTime >= PIR_RETRIGGER_DELAY))
    {
        pirDetections++;
        visitCount = calculateVisitCount(pirDetections);
        handleMotionDetection();
        lastMotionDetectionTime = currentMillis;

        Serial.print("Motion detected! PIR count: ");
        Serial.print(pirDetections);
        Serial.print(", Visits: ");
        Serial.println(visitCount);
    }

    previousMotionState = motionDetected;

    // Check Bluetooth tag
    tagDetected = isTagDetected();

    // Calculate and set fan speed
    currentFanSpeed = calculateFanSpeed(temperature, humidity);
    setFanSpeed(currentFanSpeed);

    // Set LED color based on fan status
    if (currentFanSpeed > 0)
    {
        setLEDColor(0, 0, 255); // Blue when fan is on
    }
    else
    {
        setLEDColor(0, 0, 0); // Off when fan is off
    }

    // Update display
    updateDisplay(temperature, humidity, visitCount, tagDetected);

    delay(100);
}