#include <Arduino.h>
#include "cylindricalContainer.hpp"

class WaterTankContainer {
public:
  virtual float getContentLiter( const u32 waterLevelFromSensor_cm ) = 0;
  virtual float getContentPercent( const u32 waterLevelFromSensor_cm ) = 0;
};

class CylindricalWaterTankContainer: public WaterTankContainer, public CylindricalContainer  {
  CylindricalWaterTankContainer( float hight_cm, float diameter_cm )
    :
      CylindricalContainer( hight_cm, diameter_cm)
  {

  };
  virtual float getContentLiter( const u32 waterLevelFromSensor_cm ) = 0;
  virtual float getContentPercent( const u32 waterLevelFromSensor_cm ) = 0;

};

float CylindricalWaterTankContainer::getContentLiter( const u32 sensorDistanceFromContentLevel_cm )
{
  CylindricalContainer::setContentHight_cm( sensorDistanceFromContentLevel_cm );
  return CylindricalContainer::getContentVolume_ltr();
}

float CylindricalWaterTankContainer::getContentPercent( const u32 sensorDistanceFromContentLevel_cm )
{
  CylindricalContainer::setContentHight_cm( sensorDistanceFromContentLevel_cm );
  return CylindricalContainer::getContentVolume_percent();
}