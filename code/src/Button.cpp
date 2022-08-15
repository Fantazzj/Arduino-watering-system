#include "Button.h"

Button::Button(int pin, int mode, unsigned long snubberT) {
    _init(pin, mode, snubberT);
}

Button::Button(int pin, int mode) {
    _init(pin, mode, 0);
}

void Button::_init(int pin, int mode, unsigned long snubberT) {
    _pin = pin;
    pinMode(_pin, mode);
    _oldState = digitalRead(_pin);
    _prevoiusMillis = 0;
    _snubberT = snubberT;
}

int Button::getPin() {
    return _pin;
}

unsigned long Button::getSnubberT() {
    return _snubberT;
}

void Button::setSnubberT(unsigned long snubberT) {
    _snubberT = snubberT;
}

bool Button::readRising() {
    int result;
    int newState = digitalRead(_pin);
    if((millis() - _prevoiusMillis >= _snubberT) && (_oldState < newState)) {
        _prevoiusMillis = millis();
        result = true;
    }
    else result = false;
    _oldState = newState;
    return result;
}

bool Button::readFalling() {
    int result;
    int newState = digitalRead(_pin);
    if((millis() - _prevoiusMillis >= _snubberT) && (_oldState > newState)) {
        _prevoiusMillis = millis();
        result = true;
    }
    else result = false;
    _oldState = newState;
    return result;
}

bool Button::readEdge() {
    int result;
    int newState = digitalRead(_pin);
    if((millis() - _prevoiusMillis >= _snubberT) && (_oldState != newState)) {
        _prevoiusMillis = millis();
        result = true;
    }
    else result = false;
    _oldState = newState;
    return result;
}

bool Button::readLow() {
    return digitalRead(_pin)==false;
}

bool Button::readHigh() {
    return digitalRead(_pin)==true;
}
