#include "QtValve.hpp"

QtValve::QtValve(Clock* clock, int8_t minOn, int8_t days, ControlUnit* w, int8_t num) :
	Valve(clock, minOn, days) {
	this->w = w;
	this->num = num;
}

void QtValve::turnOn() {
	tOn = etvClock->getTime();
	elapsedDays = 1;
	w->activate(num);
}

void QtValve::turnOff() {
	w->deactivate(num);
}
