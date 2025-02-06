#include "ClayValveGroup.hpp"

ClayValveGroup::ClayValveGroup(Clock& clock) :
	ValveGroup(clock) {
	w = nullptr;
}

void ClayValveGroup::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayValveGroup::turnOn(uint8_t num) {
	w->activateEtv(num);
}

void ClayValveGroup::turnOff(uint8_t num) {
	w->deactivateEtv(num);
}
