#include "ClayControlUnit.hpp"

ClayControlUnit::ClayControlUnit() :
	ui() {
	this->keypad = nullptr;

	//TODO: add definition
}

void ClayControlUnit::show() {
	ui.show();
}

void ClayControlUnit::setKeypad(ClayKeypad* keypad) {
	this->keypad = keypad;
}
