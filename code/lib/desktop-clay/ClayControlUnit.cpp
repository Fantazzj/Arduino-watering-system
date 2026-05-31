#include "ClayControlUnit.hpp"

#include <chrono>

ClayControlUnit::ClayControlUnit(ClayClock& clock) : clock{clock}, clockInfo{} {}

void ClayControlUnit::draw() {
	clock.getDayString().copy(clockInfo.DateDay, 2);
	clock.getMonthString().copy(clockInfo.DateMonth, 2);
	clock.getYearString().copy(clockInfo.DateYear, 4);
	clock.getHoursString().copy(clockInfo.TimeHours, 2);
	clock.getMinutesString().copy(clockInfo.TimeMinutes, 2);

	ui.draw(clockInfo);
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
