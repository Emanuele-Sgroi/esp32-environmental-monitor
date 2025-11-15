#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// LET'S GOOOOOOO

// First thing, I'll write "Hello World" on the oled screen

// Define constants

// oled constants
#define SCREEN_WIDTH 128    // size
#define SCREEN_HEIGHT 64    // size
#define OLED_RESET -1       // pin
#define SCREEN_ADDRESS 0x3C // address

// RGB led constants
#define LED_RED 16
#define LED_GREEN 17
#define LED_BLUE 18

// FAN constants
#define FAN_INA 25
#define FAN_INB 26

// create a display object

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ADD MAIN FUNCTIONS

// setup function

void setup()
{

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    pinMode(FAN_INA, OUTPUT);
    pinMode(FAN_INB, OUTPUT);

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
    digitalWrite(LED_RED, HIGH);
    delay(500);
    digitalWrite(LED_RED, LOW);
    delay(500);
    digitalWrite(LED_BLUE, HIGH);
    delay(500);
    digitalWrite(LED_BLUE, LOW);
    delay(500);
    digitalWrite(LED_GREEN, HIGH);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
    delay(100);
    digitalWrite(LED_GREEN, HIGH);
    delay(100);
    digitalWrite(LED_GREEN, LOW);
    delay(100);

    digitalWrite(FAN_INA, HIGH);
    digitalWrite(FAN_INB, LOW);
    delay(2000);
    digitalWrite(FAN_INA, LOW);
    digitalWrite(FAN_INB, LOW);
    delay(2000);
}