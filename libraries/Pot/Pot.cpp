#include "Pot.h"

Pot::Pot(unsigned int pin, unsigned int offset) : _pin(pin), _offset(1023 - offset){
    assert(pin >= 14 && pin <= 19); //Analog pins range from 14-19
    assert(offset < 1023); //Offset must be less than 1023
}

Pot::~Pot(){}

int Pot::value(){ return analogRead(_pin) - _offset; }

unsigned int Pot::actual(){ return analogRead(_pin); }

float Pot::percent(){ return (analogRead(_pin) / static_cast<float>(_offset)); }