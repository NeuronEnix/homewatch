#include<Arduino.h>

class I_Module {
  private:
  public:
    // pure virtual function
    virtual void exec() = 0;
    virtual void suspend() = 0;
};
