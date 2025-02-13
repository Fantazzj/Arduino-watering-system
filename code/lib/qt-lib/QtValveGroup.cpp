#include "QtValveGroup.hpp"

QtValveGroup::QtValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn) :
	ValveGroup(clock, days, minOn) {}

QtValveGroup::QtValveGroup(Clock& clock) :
	ValveGroup(clock) {}

void QtValveGroup::begin(QtControlUnit* w) {
	this->w = w;
}

void QtValveGroup::turnOn(uint8_t i) {
	this->tOn[i] = this->clock.getDateTime().time;
	this->elapsedDays[i] = 1;
	w->activateValve(i);
}

void QtValveGroup::turnOff(uint8_t i) {
	w->deactivateValve(i);
}
