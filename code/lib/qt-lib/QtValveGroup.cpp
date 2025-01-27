#include "QtValveGroup.hpp"

template<uint8_t n>
QtValveGroup<n>::QtValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn) :
	ValveGroup<n>(clock, days, minOn) {}

template<uint8_t n>
QtValveGroup<n>::QtValveGroup(Clock& clock) :
	ValveGroup<n>(clock) {}

template<uint8_t n>
void QtValveGroup<n>::turnOn(uint8_t i) {
	this->tOn[i] = this->clock.getTime().time;
	this->elapsedDays[i] = 1;
	w->activateValve(i);
}

template<uint8_t n>
void QtValveGroup<n>::turnOff(uint8_t i) {
	w->deactivateValve(i);
}
