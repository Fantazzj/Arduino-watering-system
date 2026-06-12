#include "ClayControlUnit.hpp"

#include <chrono>

ClayControlUnit::ClayControlUnit(ClayDisplay& display, ClayClock& clock, ClayKeypad& keypad, ClayValveGroup& valveGroup, ClayMainSwitch& mainSwitch, ClayMoisture& moisture, ClayDebugger& debugger) :
	display{display}, clock{clock}, keypad{keypad}, valveGroup{valveGroup}, mainSwitch{mainSwitch}, moisture{moisture}, debugger{debugger} {
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

	keypadInfo.cancelHandler = pressCancel;
	keypadInfo.downHandler = pressDown;
	keypadInfo.upHandler = pressUp;
	keypadInfo.confirmHandler = pressConfirm;
	keypadInfo.args = reinterpret_cast<intptr_t>(&keypad);

	moistureInfo.handler[0] = setMoisture00;
	moistureInfo.handler[1] = setMoisture10;
	moistureInfo.handler[2] = setMoisture20;
	moistureInfo.handler[3] = setMoisture30;
	moistureInfo.handler[4] = setMoisture40;
	moistureInfo.handler[5] = setMoisture50;
	moistureInfo.handler[6] = setMoisture60;
	moistureInfo.handler[7] = setMoisture70;
	moistureInfo.handler[8] = setMoisture80;
	moistureInfo.handler[9] = setMoisture90;
	moistureInfo.args = reinterpret_cast<intptr_t>(&moisture);
}

void ClayControlUnit::draw() {
	for(uint8_t i = 0; i < DISPLAY_HEIGHT; i++) {
		displayInfo.text[i] = display.getTextLine(i);
	}
	displayInfo.blinkChar = display.getBlinkChar();
	displayInfo.backlight = display.getBacklight();

	clock.getDayString().copy(clockInfo.DateDay, 2);
	clock.getMonthString().copy(clockInfo.DateMonth, 2);
	clock.getYearString().copy(clockInfo.DateYear, 4);
	clock.getHoursString().copy(clockInfo.TimeHours, 2);
	clock.getMinutesString().copy(clockInfo.TimeMinutes, 2);

	valveGroupInfo.states = valveGroup.getStates();
	valveGroupInfo.mainSwitch = mainSwitch.getState();

	moistureInfo.moistureLevel = moisture.getMoisture();

	debuggerInfo.text = debugger.getText().data();
	debuggerInfo.len = debugger.getText().length();

	ui.draw(displayInfo, clockInfo, keypadInfo, valveGroupInfo, moistureInfo, debuggerInfo);
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

void ClayControlUnit::setMoisture00(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(0);
}

void ClayControlUnit::setMoisture10(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(10);
}

void ClayControlUnit::setMoisture20(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(20);
}

void ClayControlUnit::setMoisture30(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(30);
}

void ClayControlUnit::setMoisture40(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(40);
}

void ClayControlUnit::setMoisture50(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(50);
}

void ClayControlUnit::setMoisture60(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(60);
}

void ClayControlUnit::setMoisture70(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(70);
}

void ClayControlUnit::setMoisture80(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(80);
}

void ClayControlUnit::setMoisture90(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayMoisture*>(args)->setMoisture(90);
}

void ClayControlUnit::pressCancel(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayKeypad*>(args)->setCancel(true);
}
void ClayControlUnit::pressDown(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayKeypad*>(args)->setDown(true);
}
void ClayControlUnit::pressUp(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayKeypad*>(args)->setUp(true);
}
void ClayControlUnit::pressConfirm(Clay_ElementId, Clay_PointerData pointerData, intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;
	reinterpret_cast<ClayKeypad*>(args)->setConfirm(true);
}
