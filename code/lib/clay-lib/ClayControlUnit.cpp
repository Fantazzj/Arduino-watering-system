#include "ClayControlUnit.hpp"

ClayControlUnit::ClayControlUnit() :
	ui() {
	//TODO: add definition
}

void ClayControlUnit::show() {
	ui.show();
}

void ClayControlUnit::setKeypad(ClayKeypad* keypad) {
	ui.setKeypad(keypad);
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

void ClayControlUnit::printOnDisplay(std::string text) {
	for(int8_t i = x, j = 0; j < text.size() && i < D_LENGTH; i++, j++) {
		ui.setDisplayChar(y, i, text[j]);
	}
}

void ClayControlUnit::setCursorDisplay(int8_t x, int8_t y) {
	this->x = x;
	this->y = y;
}

void ClayControlUnit::clearDisplay() {
	for(int8_t i = 0; i < D_HEIGHT; i++)
		for(int8_t j = 0; j < D_LENGTH; j++)
			ui.setDisplayChar(i, j, ' ');
}
