#include <Arduino.h>
#include <NewPing.h>

#include "moduleInterface.h"
#include "config-waterTank.h"

class WaterTank: public IModule
{
private:
  NewPing *ultrasonic;

public:
  WaterTank();
  ~WaterTank();
  void run ();
};

WaterTank::WaterTank()
{
  this->ultrasonic = new NewPing(waterTankConfig::ultrasonic::triggerPin, waterTankConfig::ultrasonic::echoPin);
}

WaterTank::~WaterTank()
{
  delete ultrasonic;
}

void WaterTank::run () {
  const auto distance = ultrasonic->ping_cm();

}