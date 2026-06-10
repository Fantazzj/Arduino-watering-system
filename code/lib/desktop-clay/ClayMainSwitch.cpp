#include "ClayMainSwitch.hpp"

ClayMainSwitch::ClayMainSwitch() :
	state{false} {}

void ClayMainSwitch::turnOn() {
	state = true;
}

void ClayMainSwitch::turnOff() {
	state = false;
}

bool ClayMainSwitch::getState() const {
	return state;
}
