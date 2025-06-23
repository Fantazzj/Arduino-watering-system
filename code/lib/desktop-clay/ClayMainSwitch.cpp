#include "ClayMainSwitch.hpp"

ClayMainSwitch::ClayMainSwitch() {
	w = nullptr;
}

void ClayMainSwitch::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayMainSwitch::turnOn() {
	w->activateMainSwitch();
}

void ClayMainSwitch::turnOff() {
	w->deactivateMainSwitch();
}
