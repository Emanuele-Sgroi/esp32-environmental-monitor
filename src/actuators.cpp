#include <Arduino.h>
#include "config.h"
#include "actuators.h"

void initActuators()
{
    // Initialize fan pins
    pinMode(PIN_FAN_INA, OUTPUT);
    pinMode(PIN_FAN_INB, OUTPUT);

    // Initialize LED pins
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);

    // Turn fan and led off initially
    stopFan();
    setLEDColor(0, 0, 0);

    Serial.println("Actuators initialized");
}

void setFanSpeed(int speed)
{
    // Constrain speed to valid range (0-255)
    speed = constrain(speed, 0, 255);

    if (speed == 0)
    {
        stopFan();
    }
    else
    {
        analogWrite(PIN_FAN_INA, speed);
        digitalWrite(PIN_FAN_INB, LOW);
    }
}

void stopFan()
{
    digitalWrite(PIN_FAN_INA, LOW);
    digitalWrite(PIN_FAN_INB, LOW);
}

void setLEDColor(int red, int green, int blue)
{
    // Constrain values to 0-255
    red = constrain(red, 0, 255);
    green = constrain(green, 0, 255);
    blue = constrain(blue, 0, 255);

    analogWrite(PIN_LED_RED, red);
    analogWrite(PIN_LED_GREEN, green);
    analogWrite(PIN_LED_BLUE, blue);
}

void blinkLED(int color1R, int color1G, int color1B,
              int color2R, int color2G, int color2B,
              int blinkCount, int delayMs)
{
    for (int i = 0; i < blinkCount; i++)
    {
        setLEDColor(color1R, color1G, color1B);
        delay(delayMs);
        setLEDColor(color2R, color2G, color2B);
        delay(delayMs);
    }
}