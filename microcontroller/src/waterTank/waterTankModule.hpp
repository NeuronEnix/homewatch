#include <Arduino.h>
#include <NewPing.h>

#include "moduleInterface.hpp"
#include "config-waterTank.hpp"
#include "waterTankContainer.hpp"


class WaterTankModule: public IModule
{
private:
  NewPing* ultrasonic;
  WaterTankContainer* container;

public:
  WaterTankModule();
  ~WaterTankModule();
  void exec ();
  void suspend ();
};

WaterTankModule::WaterTankModule()
{
  this->ultrasonic = new NewPing(waterTankConfig::ultrasonic::triggerPin, waterTankConfig::ultrasonic::echoPin);
}

WaterTankModule::~WaterTankModule()
{
  delete ultrasonic;
  delete container;
}

void WaterTankModule::exec () {
  const auto sensorDistanceFromWaterLevel_cm = this->ultrasonic->ping_cm();
  const auto contentLiter = this->container->getContentLiter( sensorDistanceFromWaterLevel_cm );
  const auto contentPercent = this->container->getContentPercent( sensorDistanceFromWaterLevel_cm );
}
void WaterTankModule::suspend () {
  // const auto distance = ultrasonic->ping_cm();
  delay( waterTankConfig::loopDelay_ms );
}