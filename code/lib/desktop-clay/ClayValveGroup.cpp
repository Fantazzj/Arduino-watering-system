#include "ClayValveGroup.hpp"

ClayValveGroup::ClayValveGroup(Clock& clock) :
	ValveGroup{clock}, states{} {
}

void ClayValveGroup::turnOn(const uint8_t num) {
	this->tOn[num] = this->clock.getDateTime().time;
	this->elapsedDays[num] = 1;
	states[num] = true;
}

void ClayValveGroup::turnOff(const uint8_t num) {
	states[num] = false;
}

const bool* ClayValveGroup::getStates() const {
	return states;
}
