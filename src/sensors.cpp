#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include <DHT.h>

// Create DHT sensor object
DHT dht(PIN_DHT22, DHT22);

void initSensors()
{
    // Initialise DHT22
    dht.begin();

    // Initialise PIR sensor
    pinMode(PIN_PIR, INPUT);

    Serial.println("Sensors initialized");
}

void readTempHumidity(float &temperature, float &humidity)
{
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    // Check if readings are valid
    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read from DHT sensor!");
        temperature = 0.0;
        humidity = 0.0;
    }
}

bool isMotionDetected()
{
    return digitalRead(PIN_PIR) == HIGH;
}

bool isTagDetected()
{
    // TODO: Implementation Bluetooth tag detection
    return false;
}