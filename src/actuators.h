#ifndef ACTUATORS_H
#define ACTUATORS_H

// Initialize fan and LED pins
void initActuators();

// set fan speed
void setFanSpeed(int speed);

// stop fan
void stopFan();

// Set RGB LED color
void setLEDColor(int red, int green, int blue);

// Blink LED between two colors (for motion detection)
void blinkLED(int color1R, int color1G, int color1B, int color2R, int color2G, int color2B, int blinkCount, int delayMs);

#endif