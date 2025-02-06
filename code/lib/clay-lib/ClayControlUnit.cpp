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

void ClayControlUnit::activateEtv(int8_t n) {
	ui.activateEtv(n);
}

void ClayControlUnit::deactivateEtv(int8_t n) {
	ui.deactivateEtv(n);
}

void ClayControlUnit::debuggerLog(std::string string) {
	ui.appendDebuggerText(string);
}
