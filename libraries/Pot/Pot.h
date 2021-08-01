#ifndef POT_H
#define POT_H
#include <assert.h>
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

class Pot{
    private:
        const unsigned int _pin;
        const unsigned int _offset;
    protected:

    public:
        Pot(unsigned int pin, unsigned int offset = 0);
        ~Pot();
        int value();
        unsigned int actual();
        float percent();
};
#endif