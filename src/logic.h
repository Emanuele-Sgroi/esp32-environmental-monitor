#ifndef LOGIC_H
#define LOGIC_H

// Calculate appropriate fan speed based on temperature and humidity
int calculateFanSpeed(float temperature, float humidity);

// Handle motion detection event
void handleMotionDetection();

// Calculate visit count from PIR detections
int calculateVisitCount(int pirDetections);

#endif