#include <Arduino.h>
#include <NewPing.h>

#include "moduleInterface.hpp"
#include "waterTankContainer.hpp"
#include "waterTankServer.hpp"
#include "blueprint-waterTank.hpp"

using waterTankModule::config;
using waterTankModule::CylindricalWaterTankContainer;
using waterTankModule::I_WaterTankContainer;
using waterTankModule::WaterTankModule;
using waterTankModule::WaterTankServer;

class waterTankModule::WaterTankModule : public I_Module
{
private:
  NewPing *ultrasonic;
  I_WaterTankContainer *container;
  WaterTankServer *_server;

public:
  WaterTankModule();
  ~WaterTankModule();
  void setup();
  void loop();
};

WaterTankModule::WaterTankModule()
{
  this->ultrasonic = new NewPing(config::ultrasonic::triggerPin, config::ultrasonic::echoPin);
  this->container = dynamic_cast<I_WaterTankContainer *>(new CylindricalWaterTankContainer(config::tank::hight_cm, config::tank::radius_cm));
  this->_server = new WaterTankServer(this->container);
}

WaterTankModule::~WaterTankModule()
{
  delete ultrasonic;
  delete container;
}

void WaterTankModule::loop()
{
  const auto sensorDistanceFromWaterLevel_cm = this->ultrasonic->ping_cm();
  this->container->setContentHightBySensorDistance_cm(sensorDistanceFromWaterLevel_cm);
  Serial.printf(
      "Distance: %lu | Liter: %f | Percent: %f\n",
      sensorDistanceFromWaterLevel_cm,
      this->container->getContentLiter(),
      this->container->getContentPercent());
  this->_server->loop();
  delay(config::loopDelay_ms);
}

void WaterTankModule::setup()
{
  this->_server->setup();
}
