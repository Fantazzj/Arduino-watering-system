#include "StdValveGroup.hpp"

StdValveGroup::StdValveGroup(Clock& clock) :
	ValveGroup{clock}, states{} {
}

void StdValveGroup::turnOn(const uint8_t num) {
	this->tOn[num] = this->clock.getDateTime().time;
	this->elapsedDays[num] = 1;
	states[num] = true;
}

void StdValveGroup::turnOff(const uint8_t num) {
	states[num] = false;
}

const bool* StdValveGroup::getStates() const {
	return states;
}
