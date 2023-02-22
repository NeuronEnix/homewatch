#include <Arduino.h>
#pragma once
namespace waterTankModule
{
  // Config
  struct config {
    static const unsigned long loopDelay_ms = 1000UL;
    struct ultrasonic {
      static const u8 triggerPin = D2;
      static const u8 echoPin = D4;
      static const u16 maxDistance_cm = 400;
    };
    struct tank {
      static const u16 radius_cm = 56;
      static const u16 hight_cm = 120;
      static const u16 max_water_height_cm = 102;
    };
  };
  
  // Main module
  class WaterTankModule;

  // Interface
  class I_WaterTankContainer {
  public:
    virtual float getContentLiter() const = 0;
    virtual float getContentPercent() const = 0;
    virtual I_WaterTankContainer* setContentHightBySensorDistance_cm( const u32 sensorDistanceFromContentLevel_cm ) = 0;
    virtual ~I_WaterTankContainer() = 0;
  };

  // Helper class
  class WaterTankContainer;
  class CylindricalWaterTankContainer;
  
} // namespace waterTank

waterTankModule::I_WaterTankContainer::~I_WaterTankContainer() {}

