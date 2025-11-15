#ifndef DISPLAY_H
#define DISPLAY_H

// Initialize the OLED display
void initDisplay();

// Show "Hello" message on startup
void showStartupMessage();

// Update the display with current sensor data
void updateDisplay(float temperature, float humidity, int visitCount, bool tagDetected);

#endif