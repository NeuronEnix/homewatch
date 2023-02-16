#include <Arduino.h>
#include "moduleInterface.hpp"

#ifdef MODULE_CONTEXT_WATER_TANK
  #include "module/waterTank/waterTankModule.hpp"
#endif


I_Module* module;
I_Module* getCurrentModule();

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  module = getCurrentModule();
  module->setup();
}
void loop() {
  module->loop();
}

I_Module* getCurrentModule() {
  #ifdef MODULE_CONTEXT_WATER_TANK
    return new waterTankModule::WaterTankModule();
  #endif
  return nullptr;
}