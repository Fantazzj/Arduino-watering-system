#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "../date-time-lib/MyDateTime.hpp"

class UnitDisplay {
private:
public:
	virtual void printSimpleText(const char text[]) = 0;
	virtual void printData(const char text1[], int8_t data, const char text2[]) = 0;
	virtual void printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) = 0;
	virtual void printIn(const char text[], int8_t x, int8_t y) = 0;
	virtual void printIn(int8_t data, int8_t x, int8_t y) = 0;
	virtual void showClock(MyDateTime timeIn) = 0;
	virtual void blinkAt(int8_t x, int8_t y) = 0;
	virtual void noBlink() = 0;
	virtual void clockSym(bool state) = 0;
	virtual void dropSym(bool state) = 0;
	virtual void checkSym(bool state) = 0;
	virtual void setBacklight(bool state) = 0;
	[[nodiscard]] virtual bool getBacklight() const = 0;

protected:
	bool backlightState = true;
};

#endif//DISPLAY_HPP
