#ifndef RELAY_H
#define RELAY_H
#include <assert.h>
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

class Relay{
    private:
        bool _state = false;
        unsigned int _pin;
        void _updatePin();
    protected:

    public:
        Relay(unsigned int pin);
        ~Relay();
        void toggle();
        void enable();
        void disable();
        bool isEnabled();
};
#endif