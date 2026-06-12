#include "StdMainSwitch.hpp"

StdMainSwitch::StdMainSwitch() :
	state{false} {}

void StdMainSwitch::turnOn() {
	state = true;
}

void StdMainSwitch::turnOff() {
	state = false;
}

bool StdMainSwitch::getState() const {
	return state;
}
