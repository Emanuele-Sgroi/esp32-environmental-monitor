#ifndef CONFIG_H
#define CONFIG_H

// Pin Definitions
#define PIN_DHT22 4
#define PIN_PIR 5
#define PIN_FAN_INA 25
#define PIN_FAN_INB 26
#define PIN_LED_RED 16
#define PIN_LED_GREEN 17
#define PIN_LED_BLUE 18
#define PIN_OLED_SDA 21
#define PIN_OLED_SCL 22

// OLED Display Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

// Sensor Reading Intervals (milliseconds)
#define TEMP_HUMIDITY_INTERVAL 120000 // 2 minutes

// Thresholds
#define TEMP_THRESHOLD 26.0     // Celsius
#define HUMIDITY_THRESHOLD 70.0 // Percentage

// PIR Debounce (milliseconds)
#define PIR_RETRIGGER_DELAY 3000 // Ignore motion for 3 seconds after detection

#endif