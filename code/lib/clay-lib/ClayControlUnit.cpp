#include "ClayControlUnit.hpp"

ClayControlUnit::ClayControlUnit() :
	ui() {}

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
	for(int8_t i = x, j = 0; j < text.size() && i < ClayDisplayUi::COLUMNS; i++, j++) {
		ui.setDisplayChar(y, i, text[j]);
	}
}

void ClayControlUnit::setCursorDisplay(int8_t x, int8_t y) {
	this->x = x;
	this->y = y;
}

void ClayControlUnit::clearDisplay() {
	for(int8_t i = 0; i < ClayDisplayUi::ROWS; i++)
		for(int8_t j = 0; j < ClayDisplayUi::COLUMNS; j++)
			ui.setDisplayChar(i, j, ' ');
}

void ClayControlUnit::activateMainSwitch() {
	ui.activateMainSwitch();
}

void ClayControlUnit::deactivateMainSwitch() {
	ui.deactivateMainSwitch();
}

void ClayControlUnit::hideCursorDisplay() {
	ui.setBlinkOn(-1, -1);
}

void ClayControlUnit::showCursorDisplay() {
	ui.setBlinkOn(y, x);
}

uint8_t ClayControlUnit::getMoisture() {
	return ui.getMoisture();
}
