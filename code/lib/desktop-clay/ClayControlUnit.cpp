#include "ClayControlUnit.hpp"

#include <chrono>

ClayControlUnit::ClayControlUnit(ClayClock& clock, ClayValveGroup& valveGroup, ClayMainSwitch& mainSwitch, ClayDebugger& debugger) :
	clock{clock}, valveGroup{valveGroup}, mainSwitch{mainSwitch}, debugger{debugger} {
	clockInfo.increaseOneDay = increaseOneDay;
	clockInfo.decreaseOneDay = decreaseOneDay;
	clockInfo.increaseOneMonth = increaseOneMonth;
	clockInfo.decreaseOneMonth = decreaseOneMonth;
	clockInfo.increaseOneYear = increaseOneYear;
	clockInfo.decreaseOneYear = decreaseOneYear;
	clockInfo.increaseOneHour = increaseOneHour;
	clockInfo.decreaseOneHour = decreaseOneHour;
	clockInfo.increaseOneMinute = increaseOneMinute;
	clockInfo.decreaseOneMinute = decreaseOneMinute;
	clockInfo.args = reinterpret_cast<intptr_t>(&clock);
}

void ClayControlUnit::draw() {
	clock.getDayString().copy(clockInfo.DateDay, 2);
	clock.getMonthString().copy(clockInfo.DateMonth, 2);
	clock.getYearString().copy(clockInfo.DateYear, 4);
	clock.getHoursString().copy(clockInfo.TimeHours, 2);
	clock.getMinutesString().copy(clockInfo.TimeMinutes, 2);

	valveGroupInfo.states = valveGroup.getStates();
	valveGroupInfo.mainSwitch = mainSwitch.getState();

	debuggerInfo.text = debugger.getText().data();
	debuggerInfo.len = debugger.getText().length();

	ui.draw(clockInfo, valveGroupInfo, debuggerInfo);
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

void ClayControlUnit::hideCursorDisplay() {
	ui.setBlinkOn(-1, -1);
}

void ClayControlUnit::showCursorDisplay() {
	ui.setBlinkOn(y, x);
}

void ClayControlUnit::setBacklight(const bool state) {
	ui.setBacklight(state);
}

bool ClayControlUnit::getBacklight() const {
	return ui.getBacklight();
}

uint8_t ClayControlUnit::getMoisture() const {
	return ui.getMoisture();
}

void ClayControlUnit::increaseOneDay(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->increaseOneDay();
}

void ClayControlUnit::decreaseOneDay(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->decreaseOneDay();
}

void ClayControlUnit::increaseOneMonth(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->increaseOneMonth();
}

void ClayControlUnit::decreaseOneMonth(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->decreaseOneMonth();
}

void ClayControlUnit::increaseOneYear(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->increaseOneYear();
}

void ClayControlUnit::decreaseOneYear(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->decreaseOneYear();
}

void ClayControlUnit::increaseOneHour(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->increaseOneHour();
}

void ClayControlUnit::decreaseOneHour(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->decreaseOneHour();
}

void ClayControlUnit::increaseOneMinute(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->increaseOneMinute();
}

void ClayControlUnit::decreaseOneMinute(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayClock*>(args)->decreaseOneMinute();
}
