#include "ClayControlUnit.hpp"

extern "C" {
#include "UI/clayUi.hpp"
}

ClayControlUnit::ClayControlUnit() {
	this->keypad = nullptr;

	ClayUi::init();

	//TODO: add definition
}

void ClayControlUnit::show() {
	ClayUi::show();
}

void ClayControlUnit::setKeypad(ClayKeypad* keypad) {
	this->keypad = keypad;
}
