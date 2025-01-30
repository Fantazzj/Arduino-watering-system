#include "ClayControlUnit.hpp"

ClayControlUnit::ClayControlUnit() {
	this->keypad = nullptr;

	::init();

	//TODO: add definition
}

void ClayControlUnit::show() {
	::show();
}

void ClayControlUnit::setKeypad(ClayKeypad* keypad) {
	this->keypad = keypad;
}
