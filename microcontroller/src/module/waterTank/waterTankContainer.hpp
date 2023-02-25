#include <Arduino.h>
#include "generic/cylindricalContainer.hpp"
#include "blueprint-waterTank.hpp"

using generic::CylindricalContainer;
using waterTankModule::I_WaterTankContainer, waterTankModule::CylindricalWaterTankContainer;

class waterTankModule::CylindricalWaterTankContainer : public I_WaterTankContainer, public CylindricalContainer
{

public:
  CylindricalWaterTankContainer(float hight_cm, float radius_cm)
      : CylindricalContainer(hight_cm, radius_cm) {}

  CylindricalWaterTankContainer *setContentHightBySensorDistance_cm(const u32 sensorDistanceFromContentLevel_cm);
  float getContentLiter() const;
  float getContentPercent() const;
  ~CylindricalWaterTankContainer() {}
};

CylindricalWaterTankContainer *CylindricalWaterTankContainer::setContentHightBySensorDistance_cm(const u32 sensorDistanceFromContentLevel_cm)
{
  auto contentHgt = CylindricalContainer::getHight_cm() - sensorDistanceFromContentLevel_cm;
  if (contentHgt < 0)
    contentHgt = 0;
  CylindricalContainer::setContentHight_cm(contentHgt);
  return this;
}

float CylindricalWaterTankContainer::getContentLiter() const
{
  return CylindricalContainer::getContentVolume_ltr();
}

float CylindricalWaterTankContainer::getContentPercent() const
{
  return CylindricalContainer::getContentVolume_percent();
}
