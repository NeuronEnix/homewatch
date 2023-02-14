#include <Arduino.h>
namespace waterTankConfig
{
  const unsigned long loopDelay_ms = 1000UL;

  namespace ultrasonic {
    const u8 triggerPin = 10;
    const u8 echoPin = 10;
    const u16 maxDistance_cm = 400;
  }

  namespace tank {
    const u16 maxCapacity_ltr = 112;
    const u16 hight_cm = 120;
    const u16 max_water_height_cm = 102;
  }
} // namespace waterTankConfig
