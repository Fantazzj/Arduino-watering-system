#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include "MyString.cpp"
#include "MyTime.cpp"

class Display {
private:
public:
	Display() = default;
	virtual void printSimpleText(const char text[]) {}
	virtual void printData(const char text1[], int8_t data, const char text2[]) {}
	virtual void printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) {}
	virtual void printIn(const char text[], int8_t x, int8_t y) {}
	virtual void printIn(int8_t data, int8_t x, int8_t y) {}
	virtual void showClock(MyTime timeIn) {}
	virtual void blinkAt(int8_t x, int8_t y) {}
	virtual void noBlink() {}
	virtual void clockSym() {}
	virtual void noClockSym() {}
	virtual void dropSym() {}
	virtual void noDropSym() {}
	virtual void checkSym() {}
	virtual void noCheckSym() {}
	virtual void noSymbols() {
		noClockSym();
		noDropSym();
		noCheckSym();
	}
	virtual void backlight() {}
	virtual void noBacklight() {}

protected:
};

#endif
