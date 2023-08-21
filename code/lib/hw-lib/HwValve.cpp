#include "HwValve.hpp"

HwValve::HwValve(Clock* etvClock, int8_t minOn, int8_t days, int8_t pin) :
	Valve(etvClock, minOn, days) {
	this->pin = pin;
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
}

void HwValve::turnOn() {
	tOn = etvClock->getTime().time;
	elapsedDays = 1;
	digitalWrite(pin, LOW);
}

void HwValve::turnOff() {
	digitalWrite(pin, HIGH);
}
