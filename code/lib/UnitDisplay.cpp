#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include "MyString.cpp"
#include "MyTime.cpp"

class UnitDisplay {
private:
public:
	UnitDisplay() = default;
	virtual void printSimpleText(char text[]) {}
	virtual void printData(char text1[], int8_t data, char text2[]) {}
	virtual void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) {}
	virtual void printIn(char text[], int8_t x, int8_t y) {}
	virtual void printIn(int8_t data, int8_t x, int8_t y) {}
	virtual void showClock(MyTime timeIn) {}
	virtual void blinkAt(int8_t x, int8_t y) {}
	virtual void noBlink() {}
	virtual void clockSym() {}
	virtual void noClockSym() {}
	virtual void dropSym() {}
	virtual void DisplaynoDropSym() {}
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
