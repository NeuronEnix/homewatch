#include <Arduino.h>
namespace generic
{
  class CylindricalContainer;
}
using generic::CylindricalContainer;

class CylindricalContainer
{
private:
  float _hight_cm;
  float _radius_cm;
  float _contentHight_cm;
  float volumeOfCylinder(float r, float h) const { return PI * r * r * h; };

public:
  CylindricalContainer(float hight_cm, float radius_cm);

  // getters
  float getHight_cm() const { return this->_hight_cm; };
  float getRadius_cm() const { return this->_radius_cm; };
  float getContentLevel_cm() const { return this->_contentHight_cm; };

  // setters
  CylindricalContainer *setContentHight_cm(float contentHight_cm)
  {
    this->_contentHight_cm = contentHight_cm;
    return this;
  }

  // computers
  float getTotalVolume_ltr() const;
  float getContentVolume_ltr() const;
  float getContentVolume_percent() const;
  ~CylindricalContainer();
};

CylindricalContainer::CylindricalContainer(float hight_cm, float radius_cm)
{
  this->_hight_cm = hight_cm;
  this->_radius_cm = radius_cm;
}

float CylindricalContainer::getTotalVolume_ltr() const
{
  return this->volumeOfCylinder(this->_radius_cm, this->_hight_cm) / 1000;
}

float CylindricalContainer::getContentVolume_ltr() const
{
  return this->volumeOfCylinder(this->_radius_cm, this->_contentHight_cm) / 1000;
}
float CylindricalContainer::getContentVolume_percent() const
{
  return this->getContentVolume_ltr() * 100 / this->getTotalVolume_ltr();
}
CylindricalContainer::~CylindricalContainer() {}
