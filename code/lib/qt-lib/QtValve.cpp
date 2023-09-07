#include "QtValve.hpp"

QtValve::QtValve(Clock* clock, uint8_t minOn, uint8_t days, ControlUnit* w, uint8_t num) :
	Valve(clock, minOn, days) {
	this->w = w;
	this->num = num;
}

void QtValve::turnOn() {
	tOn = etvClock->getTime().time;
	elapsedDays = 1;
	w->activateValve(num);
}

void QtValve::turnOff() {
	w->deactivateValve(num);
}
