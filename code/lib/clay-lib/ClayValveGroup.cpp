#include "ClayValveGroup.hpp"

ClayValveGroup::ClayValveGroup(Clock& clock) :
	ValveGroup(clock) {
	//TODO: add definition
}

void ClayValveGroup::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayValveGroup::turnOn(uint8_t num) {
	//TODO: add definition
}

void ClayValveGroup::turnOff(uint8_t num) {
	//TODO: add definition
}
