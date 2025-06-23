#include "ClayControlUnit.hpp"

ClayControlUnit::ClayControlUnit() = default;

void ClayControlUnit::show() {
	ui.show();
}

bool ClayControlUnit::getCancelState() {
	return ui.getCancelState();
}

bool ClayControlUnit::getDownState() {
	return ui.getDownState();
}

bool ClayControlUnit::getUpState() {
	return ui.getUpState();
}

bool ClayControlUnit::getConfirmState() {
	return ui.getConfirmState();
}

bool ClayControlUnit::getGeneralState() const {
	return ui.getGeneralState();
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

void ClayControlUnit::setBacklight(bool state) {
	ui.setBacklight(state);
}

bool ClayControlUnit::getBacklight() const {
	return ui.getBacklight();
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
