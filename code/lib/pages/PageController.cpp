#ifndef PAGE_CONTROLLER_CPP
#define PAGE_CONTROLLER_CPP

#include "../Clock.cpp"
#include "../Display.cpp"
#include "../Keypad.cpp"
#include "../Valve.cpp"

enum KeypadButton : int8_t {
	NoBtn,
	Cancel,
	Down,
	Up,
	Confirm
};

/*#define KeypadButton int8_t
#define NoBtn 0
#define Cancel 1
#define Down 2
#define Up 3
#define Confirm 4*/

class PageController {
private:
	Keypad* _myKeypad;
	Display* _myDisplay;
	Clock* _myClock;
	Valve** _myEtv;
	AutoCycle* _autoCycle;
	bool _timeToEdit;

public:
	PageController(Keypad* myKeypad, Display* myDisplay, Clock* myClock, Valve* myEtv[], AutoCycle* autoCycle) {
		_myKeypad = myKeypad;
		_myDisplay = myDisplay;
		_myClock = myClock;
		_myEtv = myEtv;
		_autoCycle = autoCycle;
		_timeToEdit = true;
	}

	KeypadButton keypad() {
		if(_myKeypad->cancel()) return Cancel;
		if(_myKeypad->down()) return Down;
		if(_myKeypad->up()) return Up;
		if(_myKeypad->confirm()) return Confirm;
		else return NoBtn;
	}
	bool getTimeToEdit() { return _timeToEdit; }
	bool setTimeToEdit(bool state) { _timeToEdit = state; }
	bool keypadGeneral() { return _myKeypad->generalPressed(); }
	void displayPrint(char text[]) { _myDisplay->printSimpleText(text); }
	void displayPrint(char text[], int8_t x, int8_t y) { _myDisplay->printIn(text, x, y); }
	void displayPrint(int8_t num, int8_t x, int8_t y) { _myDisplay->printIn(num, x, y); }
	void displayPrint(char text1[], int8_t data, char text2[]) { _myDisplay->printData(text1, data, text2); }
	void displayPrint(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) { _myDisplay->printData(text1, data1, text2, data2, text3); }
	void displayPrint(MyTime time) { _myDisplay->showClock(time); }
	void displayDrop(bool state) {
		if(state) _myDisplay->dropSym();
		else _myDisplay->noDropSym();
	}
	void displayClock(bool state) {
		if(state) _myDisplay->clockSym();
		else _myDisplay->noClockSym();
	}
	void displayCheck(bool state) {
		if(state) _myDisplay->checkSym();
		else _myDisplay->noCheckSym();
	}
	void displayShowCursor(int8_t x, int8_t y) { _myDisplay->blinkAt(x, y); }
	void displayHideCursor() { _myDisplay->noBlink(); }
	void displaySetBacklight(bool state) {
		if(state) _myDisplay->backlight();
		else _myDisplay->noBacklight();
	}
	int8_t getEtvOn() { return _autoCycle->etvOn; }
	void setEtvOn(int8_t num) { _autoCycle->etvOn = num; }
	int8_t getEtvNum() { return _autoCycle->etvNum; }
	void setEtvState(int8_t num, bool state) {
		if(state) _myEtv[num]->turnOn();
		else _myEtv[num]->turnOff();
	}
	void setEtvDays(int8_t num, int8_t days) { _myEtv[num]->days = days; }
	int8_t getEtvDays(int8_t num) { return _myEtv[num]->days; }
	void setEtvMinOn(int8_t num, int8_t minOn) { _myEtv[num]->minOn = minOn; }
	int8_t getEtvMinOn(int8_t num) { return _myEtv[num]->minOn; }
	MyTime clockGetTime() { return _myClock->getTime(); }
	void clockSetTime(MyTime timeIn) {
		_myClock->setTime(timeIn);
		setTimeToEdit(false);
	}
	void autoCycleSetWatered(bool mode) { _autoCycle->watered = mode; }
	bool autoCycleGetWatered() { return _autoCycle->watered; }
	void autoCycleSetStarted(bool mode) { _autoCycle->started = mode; }
	bool autoCycleGetStarted() { return _autoCycle->started; }
	void autoCycleSetTStart(MyTime timeIn) { _autoCycle->tStart = timeIn; }
	MyTime autoCycleGetTStart() { return _autoCycle->tStart; }


protected:
};

#endif
