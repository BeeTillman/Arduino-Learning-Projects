#include "SR04.h"

// Pins
int triggerPin = 12;
int echoPin = 11;

// Get an instance of an SR04
SR04 sensor = SR04(echoPin, triggerPin);

// Var for distance measurements
long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensor.Distance();
  Serial.println(distance);
  delay(1000);
}
