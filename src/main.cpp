#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// LET'S GOOOOOOO

// First thing, I'll write "Hello World" on the oled screen

// Define constants

#define SCREEN_WIDTH 128    // size
#define SCREEN_HEIGHT 64    // size
#define OLED_RESET -1       // pin
#define SCREEN_ADDRESS 0x3C // address

// create a display object

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ADD MAIN FUNCTIONS

// setup function

void setup()
{
    Serial.begin(115200); // USB communication
    Wire.begin(21, 22);   // Initialize I2C

    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println("SSD1306 allocation failed");
        for (;;)
            ;
    }

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 2);

    display.println("Hello World");

    display.display();
    Serial.println("OLED initialized successfully!");
}

void loop()
{
}