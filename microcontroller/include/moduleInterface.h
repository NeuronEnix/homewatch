#include<Arduino.h>

class IModule {
  private:
  public:
    // pure virtual function
    virtual void run() = 0;
};
