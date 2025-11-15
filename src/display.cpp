#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "display.h"

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initDisplay()
{
    // Initialize I2C
    Wire.begin(PIN_OLED_SDA, PIN_OLED_SCL);

    // Initialize display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println("SSD1306 allocation failed");
        for (;;)
            ;
    }

    Serial.println("Display initialized");
}

void showStartupMessage()
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 25);
    display.println("Hello");
    display.display();
    delay(2000); // Show for 2 seconds
}

void updateDisplay(float temperature, float humidity, int visitCount, bool tagDetected)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // temperature
    display.setCursor(0, 1);
    display.print("Temp: ");
    display.print(temperature, 1);
    display.println(" C");

    // humidity
    display.setCursor(0, 12);
    display.print("Hum: ");
    display.print(humidity, 1);
    display.println(" %");

    // visit counts
    display.setCursor(0, 24);
    display.print("Visits: ");
    display.println(visitCount);

    // Display tag status if detected
    if (tagDetected)
    {
        display.setCursor(0, 36);
        display.println("tag1");
    }

    display.display();
}