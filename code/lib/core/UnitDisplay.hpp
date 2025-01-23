#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "MyDateTime.hpp"

class UnitDisplay {
private:
public:
	UnitDisplay() = default;
	virtual void printSimpleText(char text[]);
	virtual void printData(char text1[], int8_t data, char text2[]);
	virtual void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]);
	virtual void printIn(char text[], int8_t x, int8_t y);
	virtual void printIn(int8_t data, int8_t x, int8_t y);
	virtual void showClock(MyDateTime timeIn);
	virtual void blinkAt(int8_t x, int8_t y);
	virtual void noBlink();
	virtual void clockSym(bool state);
	virtual void dropSym(bool state);
	virtual void checkSym(bool state);
	virtual void backlight(bool state);
	bool getBacklight();

protected:
	bool backlightState = true;
};

#endif//DISPLAY_HPP
