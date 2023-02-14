#include <Arduino.h>
#include "generic/cylindricalContainer.hpp"
#include "blueprint-waterTank.hpp"

using waterTankModule::I_WaterTankContainer, waterTankModule::CylindricalWaterTankContainer;
using generic::CylindricalContainer;

class waterTankModule::CylindricalWaterTankContainer: public I_WaterTankContainer, public CylindricalContainer  {
  
public:
  CylindricalWaterTankContainer( float hight_cm, float radius_cm )
    : CylindricalContainer( hight_cm, radius_cm) {}

  float getContentLiter( const u32 sensorDistanceFromContentLevel_cm );
  float getContentPercent( const u32 sensorDistanceFromContentLevel_cm );
  ~CylindricalWaterTankContainer(){}

};

float CylindricalWaterTankContainer::getContentLiter( const u32 sensorDistanceFromContentLevel_cm ) {
  auto contentHgt = CylindricalContainer::getHight_cm() - sensorDistanceFromContentLevel_cm;
  if ( contentHgt < 0 ) contentHgt = 0;
  CylindricalContainer::setContentHight_cm( contentHgt );
  return CylindricalContainer::getContentVolume_ltr();
}

float CylindricalWaterTankContainer::getContentPercent( const u32 sensorDistanceFromContentLevel_cm ) {
  auto contentHgt = CylindricalContainer::getHight_cm() - sensorDistanceFromContentLevel_cm;
  if ( contentHgt < 0 ) contentHgt = 0;
  CylindricalContainer::setContentHight_cm( contentHgt );
  return CylindricalContainer::getContentVolume_percent();
}

