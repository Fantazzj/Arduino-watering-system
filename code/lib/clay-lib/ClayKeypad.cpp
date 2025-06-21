#include "ClayKeypad.hpp"

ClayKeypad::ClayKeypad() = default;

void ClayKeypad::begin(ClayControlUnit* w) {
	this->w = w;
}

bool ClayKeypad::cancel() {
	return w->getCancelState();
}

bool ClayKeypad::down() {
	return w->getDownState();
}

bool ClayKeypad::up() {
	return w->getUpState();
}

bool ClayKeypad::confirm() {
	return w->getConfirmState();
}

bool ClayKeypad::generalPressed() {
	return w->getGeneralState();
}
