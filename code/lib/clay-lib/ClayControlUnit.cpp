#include "ClayControlUnit.hpp"

ClayControlUnit::ClayControlUnit() :
	ui() {}

void ClayControlUnit::show() {
	ui.show();
}

void ClayControlUnit::setKeypad(ClayKeypad* keypad) {
	ui.setKeypad(keypad);
}

void ClayControlUnit::activateEtv(const uint8_t n) {
	ui.activateEtv(n);
}

void ClayControlUnit::deactivateEtv(const uint8_t n) {
	ui.deactivateEtv(n);
}

void ClayControlUnit::debuggerLog(const std::string& string) {
	ui.appendDebuggerText(string);
}

void ClayControlUnit::printOnDisplay(const std::string& text) {
	for(int8_t i = x, j = 0; j < text.size() && i < DISPLAY_LENGTH; i++, j++) {
		ui.setDisplayChar(y, i, text[j]);
	}
}

void ClayControlUnit::setCursorDisplay(const int8_t x, const int8_t y) {
	this->x = x;
	this->y = y;
}

void ClayControlUnit::clearDisplay() {
	for(int8_t i = 0; i < DISPLAY_HEIGHT; i++)
		for(int8_t j = 0; j < DISPLAY_LENGTH; j++)
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

uint8_t ClayControlUnit::getMoisture() const {
	return ui.getMoisture();
}

void ClayControlUnit::setDateTime(const std::chrono::local_time<std::chrono::seconds> dateTime) {
	ui.setDateTime(dateTime);
}

std::chrono::local_time<std::chrono::seconds> ClayControlUnit::getDateTime() const {
	return ui.getDateTime();
}
