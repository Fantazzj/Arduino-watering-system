#include "QtValve.hpp"

QtValve::QtValve(Clock& clock, uint8_t minOn, uint8_t days, uint8_t num) :
	Valve(clock, minOn, days) {
	this->num = num;
}

QtValve::QtValve(Clock& clock, uint8_t num) :
	Valve(clock, 0, 0) {
	this->num = num;
}

void QtValve::begin(ControlUnit* w) {
	this->w = w;
}

void QtValve::turnOn() {
	tOn = etvClock.getDateTime().time;
	elapsedDays = 1;
	w->activateValve(num);
}

void QtValve::turnOff() {
	w->deactivateValve(num);
}
