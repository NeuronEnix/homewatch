#pragma once
#include <Arduino.h>

class I_Module
{
private:
public:
  // pure virtual function
  virtual void setup() = 0;
  virtual void loop() = 0;
};
