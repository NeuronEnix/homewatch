#include<Arduino.h>

class IModule {
  private:
  public:
    // pure virtual function
    virtual void exec() = 0;
    virtual void suspend() = 0;
};
