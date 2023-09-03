#include "PageController.hpp"

PageController::PageController(Keypad* myKeypad, UnitDisplay* myDisplay, Clock* myClock, Valve* myEtv[], Memory* myMemory, AutoCycle* autoCycle) {
	_myKeypad = myKeypad;
	_myDisplay = myDisplay;
	_myClock = myClock;
	_myEtv = myEtv;
	_myMemory = myMemory;
	_autoCycle = autoCycle;
	_timeToEdit = true;
}

KeypadButton PageController::keypad() {
	if(_myKeypad->cancel()) return Cancel;
	if(_myKeypad->down()) return Down;
	if(_myKeypad->up()) return Up;
	if(_myKeypad->confirm()) return Confirm;
	else return NoBtn;
}
bool PageController::getTimeToEdit() { return _timeToEdit; }
void PageController::setTimeToEdit(bool state) { _timeToEdit = state; }
bool PageController::keypadGeneral() { return _myKeypad->generalPressed(); }
void PageController::displayPrint(char text[]) { _myDisplay->printSimpleText(text); }
void PageController::displayPrint(char text[], int8_t x, int8_t y) { _myDisplay->printIn(text, x, y); }
void PageController::displayPrint(int8_t num, int8_t x, int8_t y) { _myDisplay->printIn(num, x, y); }
void PageController::displayPrint(char text1[], int8_t data, char text2[]) { _myDisplay->printData(text1, data, text2); }
void PageController::displayPrint(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) { _myDisplay->printData(text1, data1, text2, data2, text3); }
void PageController::displayPrint(MyDateTime time) { _myDisplay->showClock(time); }
void PageController::displayDrop(bool state) {
	if(state) _myDisplay->dropSym();
	else _myDisplay->noDropSym();
}
void PageController::displayClock(bool state) {
	if(state) _myDisplay->clockSym();
	else _myDisplay->noClockSym();
}
void PageController::displayCheck(bool state) {
	if(state) _myDisplay->checkSym();
	else _myDisplay->noCheckSym();
}
void PageController::displayShowCursor(int8_t x, int8_t y) { _myDisplay->blinkAt(x, y); }
void PageController::displayHideCursor() { _myDisplay->noBlink(); }
void PageController::displaySetBacklight(bool state) {
	if(state) _myDisplay->backlight();
	else _myDisplay->noBacklight();
}
bool PageController::displayGetBacklight() { return _myDisplay->getBacklight(); }
int8_t PageController::getEtvOn() { return _autoCycle->etvOn; }
void PageController::setEtvOn(int8_t num) { _autoCycle->etvOn = num; }
int8_t PageController::getEtvNum() { return _autoCycle->etvNum; }
void PageController::setEtvState(int8_t num, bool state) {
	if(state) _myEtv[num]->turnOn();
	else _myEtv[num]->turnOff();
}
void PageController::setEtvDays(int8_t num, int8_t days) {
	_myEtv[num]->days = days;
	_myMemory->saveEtvDays(num, days);
}
int8_t PageController::getEtvDays(int8_t num) {
	return _myEtv[num]->days;
}
void PageController::setEtvMinOn(int8_t num, int8_t minOn) {
	_myEtv[num]->minOn = minOn;
	_myMemory->saveEtvMinOn(num, minOn);
}
int8_t PageController::getEtvMinOn(int8_t num) {
	return _myEtv[num]->minOn;
}
MyDateTime PageController::clockGetTime() { return _myClock->getTime(); }
void PageController::clockSetTime(MyDateTime timeIn) {
	_myClock->setTime(timeIn);
	setTimeToEdit(false);
}
void PageController::autoCycleSetWatered(bool mode) { _autoCycle->watered = mode; }
bool PageController::autoCycleGetWatered() { return _autoCycle->watered; }
void PageController::autoCycleSetStarted(bool mode) { _autoCycle->started = mode; }
bool PageController::autoCycleGetStarted() { return _autoCycle->started; }
void PageController::autoCycleSetTStart(MyTime timeIn) {
	_autoCycle->tStart = timeIn;
	_myMemory->saveStartTime(timeIn);
}
MyTime PageController::autoCycleGetTStart() { return _autoCycle->tStart; }
