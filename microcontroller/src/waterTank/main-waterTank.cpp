#include <Arduino.h>
#include <WiFiManager.h>

#include "waterTankModule.hpp"

WaterTankModule waterTank;
WiFiManager wifiManager;

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  wifiManager.autoConnect("WaterTankAP");

}
void loop() {
  waterTank.exec();
  waterTank.suspend();
}