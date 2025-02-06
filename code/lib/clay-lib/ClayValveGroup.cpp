#include "ClayValveGroup.hpp"

ClayValveGroup::ClayValveGroup(Clock& clock) :
	ValveGroup(clock) {
	w = nullptr;
}

void ClayValveGroup::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayValveGroup::turnOn(uint8_t num) {
	this->tOn[num] = this->clock.getDateTime().time;
	this->elapsedDays[num] = 1;
	w->activateEtv(num);
}

void ClayValveGroup::turnOff(uint8_t num) {
	w->deactivateEtv(num);
}
