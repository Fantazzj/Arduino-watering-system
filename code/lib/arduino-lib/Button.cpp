#include "Button.h"

Button::Button(uint8_t pin, uint8_t mode, uint32_t snubberT) {
	_init(pin, mode, snubberT);
}

Button::Button(uint8_t pin, uint8_t mode) {
	_init(pin, mode, 0);
}

void Button::_init(uint8_t pin, uint8_t mode, uint32_t snubberT) {
	_pin = pin;
	pinMode(_pin, mode);
	_oldState = digitalRead(_pin);
	_prevoiusMillis = 0;
	_snubberT = snubberT;
}

uint8_t Button::getPin() {
	return _pin;
}

uint32_t Button::getSnubberT() {
	return _snubberT;
}

void Button::setSnubberT(uint32_t snubberT) {
	_snubberT = snubberT;
}

bool Button::readRising() {
	uint8_t result;
	uint8_t newState = digitalRead(_pin);
	if((millis() - _prevoiusMillis >= _snubberT) && (_oldState < newState)) {
		_prevoiusMillis = millis();
		result = true;
	} else result = false;
	_oldState = newState;
	return result;
}

bool Button::readFalling() {
	uint8_t result;
	uint8_t newState = digitalRead(_pin);
	if((millis() - _prevoiusMillis >= _snubberT) && (_oldState > newState)) {
		_prevoiusMillis = millis();
		result = true;
	} else result = false;
	_oldState = newState;
	return result;
}

bool Button::readEdge() {
	uint8_t result;
	uint8_t newState = digitalRead(_pin);
	if((millis() - _prevoiusMillis >= _snubberT) && (_oldState != newState)) {
		_prevoiusMillis = millis();
		result = true;
	} else result = false;
	_oldState = newState;
	return result;
}

bool Button::readLow() {
	return digitalRead(_pin) == false;
}

bool Button::readHigh() {
	return digitalRead(_pin) == true;
}
