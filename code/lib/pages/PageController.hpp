#ifndef PAGE_CONTROLLER_HPP
#define PAGE_CONTROLLER_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "../core/AutoCycle.hpp"
#include "../core/Clock.hpp"
#include "../core/Keypad.hpp"
#include "../core/Memory.hpp"
#include "../core/UnitDisplay.hpp"
#include "../core/Valve.hpp"

enum KeypadButton : uint8_t {
	Cancel,
	Up,
	Down,
	Confirm,
	NoBtn
};

class PageController {
private:
	Keypad* _myKeypad;
	UnitDisplay* _myDisplay;
	Clock* _myClock;
	Valve** _myEtv;
	Memory* _myMemory;
	AutoCycle* _autoCycle;
	bool _timeToEdit;

public:
	PageController(Keypad* myKeypad, UnitDisplay* myDisplay, Clock* myClock, Valve* myEtv[], Memory* myMemory, AutoCycle* autoCycle);
	KeypadButton keypad();
	bool getTimeToEdit();
	void setTimeToEdit(bool state);
	bool keypadGeneral();
	void displayPrint(char text[]);
	void displayPrint(char text[], int8_t x, int8_t y);
	void displayPrint(int8_t num, int8_t x, int8_t y);
	void displayPrint(char text1[], int8_t data, char text2[]);
	void displayPrint(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]);
	void displayPrint(MyDateTime time);
	void displayDrop(bool state);
	void displayClock(bool state);
	void displayCheck(bool state);
	void displayShowCursor(int8_t x, int8_t y);
	void displayHideCursor();
	void displaySetBacklight(bool state);
	int8_t getEtvOn();
	void setEtvOn(int8_t num);
	int8_t getEtvNum();
	void setEtvState(int8_t num, bool state);
	void setEtvDays(int8_t num, int8_t days);
	int8_t getEtvDays(int8_t num);
	void setEtvMinOn(int8_t num, int8_t minOn);
	int8_t getEtvMinOn(int8_t num);
	MyDateTime clockGetTime();
	void clockSetTime(MyDateTime timeIn);
	void autoCycleSetWatered(bool mode);
	bool autoCycleGetWatered();
	void autoCycleSetStarted(bool mode);
	bool autoCycleGetStarted();
	void autoCycleSetTStart(MyTime timeIn);
	MyTime autoCycleGetTStart();

protected:
};

#endif
