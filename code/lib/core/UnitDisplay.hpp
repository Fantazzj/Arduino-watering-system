#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "../date-time/MyDateTime.hpp"

class UnitDisplay {
private:
public:
	UnitDisplay() = default;
	virtual void printSimpleText(char text[]) = 0;
	virtual void printData(char text1[], int8_t data, char text2[]) = 0;
	virtual void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) = 0;
	virtual void printIn(char text[], int8_t x, int8_t y) = 0;
	virtual void printIn(int8_t data, int8_t x, int8_t y) = 0;
	virtual void showClock(MyDateTime timeIn) = 0;
	virtual void blinkAt(int8_t x, int8_t y) = 0;
	virtual void noBlink() = 0;
	virtual void clockSym(bool state) = 0;
	virtual void dropSym(bool state) = 0;
	virtual void checkSym(bool state) = 0;
	virtual void backlight(bool state);
	bool getBacklight();

protected:
	bool backlightState = true;
};

#endif//DISPLAY_HPP
