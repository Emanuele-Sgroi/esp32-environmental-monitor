#include <Arduino.h>
#include "config.h"
#include "logic.h"
#include "actuators.h"

int calculateFanSpeed(float temperature, float humidity)
{
    int speed = 0;

    // check temperature
    if (temperature > TEMP_THRESHOLD)
    {
        float tempDiff = temperature - TEMP_THRESHOLD;
        // For every degree above threshold, increase speed by 25
        // Max out at 255 (full speed)
        speed = (int)(tempDiff * 25);
    }

    // check humidity
    if (humidity > HUMIDITY_THRESHOLD)
    {
        float humidityDiff = humidity - HUMIDITY_THRESHOLD;

        // For every 5% above threshold, increase speed by 25
        int humiditySpeed = (int)(humidityDiff / 5.0 * 25);
        // Use the higher of temperature-based or humidity-based speed
        speed = max(speed, humiditySpeed);
    }

    // Constrain to valid PWM range
    speed = constrain(speed, 0, 255);

    return speed;
}

void handleMotionDetection()
{
    // Blink red and green 5 times, 200ms delay
    blinkLED(255, 0, 0, // Red (color 1)
             0, 255, 0, // Green (color 2)
             5,         // Blink 5 times
             200);      // 200ms between blinks
}

int calculateVisitCount(int pirDetections)
{
    return pirDetections / 2;
}