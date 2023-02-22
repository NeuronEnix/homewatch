#include <Arduino.h>
#include <NewPing.h>
#include <WiFiManager.h>

#include "moduleInterface.hpp"
#include "waterTankContainer.hpp"
#include "blueprint-waterTank.hpp"


using waterTankModule::I_WaterTankContainer;
using waterTankModule::WaterTankModule;
using waterTankModule::CylindricalWaterTankContainer;
using waterTankModule::config;

class waterTankModule::WaterTankModule: public I_Module
{
private:
  NewPing* ultrasonic;
  I_WaterTankContainer* container;
  WiFiManager wifiManager;

public:
  WaterTankModule();
  ~WaterTankModule();
  void setup ();
  void loop ();
};

WaterTankModule::WaterTankModule() {
  this->ultrasonic = new NewPing(config::ultrasonic::triggerPin, config::ultrasonic::echoPin);
  this->container = dynamic_cast<I_WaterTankContainer*>(new CylindricalWaterTankContainer(config::tank::hight_cm, config::tank::radius_cm));
}

WaterTankModule::~WaterTankModule() {
  delete ultrasonic;
  delete container;
}

void WaterTankModule::loop () {
  const auto sensorDistanceFromWaterLevel_cm = this->ultrasonic->ping_cm();
  this->container->setContentHightBySensorDistance_cm( sensorDistanceFromWaterLevel_cm );
  Serial.printf(
    "Distance: %lu | Liter: %f | Percent: %f\n",
    sensorDistanceFromWaterLevel_cm,
    this->container->getContentLiter(),
    this->container->getContentPercent()
  );
  delay( config::loopDelay_ms );
}

void WaterTankModule::setup () {
  wifiManager.autoConnect("WaterTankAP");
}