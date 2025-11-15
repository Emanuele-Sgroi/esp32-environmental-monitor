#ifndef SENSORS_H
#define SENSORS_H

// Initialise all sensors
void initSensors();

// Read temperature and humidity from DHT22
void readTempHumidity(float &temperature, float &humidity);

// Check PIR detection
bool isMotionDetected();

// Check if Bluetooth tag is detected
bool isTagDetected();

// Scan for Bluetooth beacon
void scanForBeacon();

#endif