#include "HwValve.hpp"
#include <Arduino.h>

HwValve::HwValve(Clock& etvClock, uint8_t minOn, uint8_t days, uint8_t pin) :
	Valve(etvClock, minOn, days) {
	this->pin = pin;
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
}

HwValve::HwValve(Clock& etvClock, uint8_t pin) :
	Valve(etvClock, 0, 0) {
	this->pin = pin;
}

void HwValve::begin() {
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
}

void HwValve::turnOn() {
	tOn = etvClock.getDateTime().time;
	elapsedDays = 1;
	digitalWrite(pin, LOW);
}

void HwValve::turnOff() {
	digitalWrite(pin, HIGH);
}
