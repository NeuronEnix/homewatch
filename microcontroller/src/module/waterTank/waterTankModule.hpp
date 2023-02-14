#include <Arduino.h>
#include <NewPing.h>

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

public:
  WaterTankModule();
  ~WaterTankModule();
  void exec ();
  void suspend ();
};

WaterTankModule::WaterTankModule() {
  this->ultrasonic = new NewPing(config::ultrasonic::triggerPin, config::ultrasonic::echoPin);
  this->container = dynamic_cast<I_WaterTankContainer*>(new CylindricalWaterTankContainer(config::tank::hight_cm, config::tank::radius_cm));
}

WaterTankModule::~WaterTankModule() {
  delete ultrasonic;
  delete container;
}

void WaterTankModule::exec () {
  const auto sensorDistanceFromWaterLevel_cm = this->ultrasonic->ping_cm();
  const auto contentLiter = this->container->getContentLiter( sensorDistanceFromWaterLevel_cm );
  const auto contentPercent = this->container->getContentPercent( sensorDistanceFromWaterLevel_cm );
  Serial.printf("Distance: %lu | Liter: %f | Percent: %f\n", sensorDistanceFromWaterLevel_cm, contentLiter, contentPercent );
}

void WaterTankModule::suspend () {
  // const auto distance = ultrasonic->ping_cm();
  delay( config::loopDelay_ms );
}