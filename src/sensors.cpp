#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include <DHT.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

// Create DHT sensor object
DHT dht(PIN_DHT22, DHT22);

// BLE scanning variables - DECLARE BEFORE THE CLASS
BLEScan *pBLEScan = nullptr;
bool beaconFound = false;

// BLE Scan callback class
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice advertisedDevice)
    {
        String deviceName = advertisedDevice.getName().c_str();

        if (deviceName.indexOf("CP27") >= 0 ||
            deviceName.indexOf("iBeacon") >= 0 ||
            advertisedDevice.haveServiceUUID())
        {
            beaconFound = true;
            Serial.print("Beacon found: ");
            Serial.println(deviceName);
        }
    }
};

void initSensors()
{
    // Initialise DHT22
    dht.begin();

    // Initialise PIR sensor
    pinMode(PIN_PIR, INPUT);

    // Initialize BLE
    BLEDevice::init("");
    pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
    pBLEScan->setActiveScan(true);
    pBLEScan->setInterval(100);
    pBLEScan->setWindow(99);

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
    return beaconFound;
}

void scanForBeacon()
{
    beaconFound = false; // Reset before scanning
    BLEScanResults foundDevices = pBLEScan->start(BEACON_SCAN_DURATION, false);
    pBLEScan->clearResults();
}