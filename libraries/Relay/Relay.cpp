#include "Relay.h"

Relay::Relay(unsigned int pin) : _pin(pin){
    assert(pin <= 13); //Digital pins range from 0-13
    pinMode(pin, OUTPUT);
    _state = false;
    _updatePin();
}

Relay::~Relay(){}

void Relay::toggle(){
    _state = !_state;
    _updatePin();
}

void Relay::enable(){
    _state = true;
    _updatePin();
}

void Relay::disable(){
    _state = false;
    _updatePin();
}

bool Relay::isEnabled(){ return _state; }

void Relay::_updatePin(){ digitalWrite(_pin, _state); }