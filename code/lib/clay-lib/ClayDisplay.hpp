#ifndef CLAYDISPLAY_HPP
#define CLAYDISPLAY_HPP

#include "../core-lib/UnitDisplay.hpp"
#include "ClayControlUnit.hpp"

class ClayDisplay : public UnitDisplay {
private:
	ClayControlUnit* w;

public:
	explicit ClayDisplay();
	void begin(ClayControlUnit* w);
	void printSimpleText(const char text[]) override;
	void printData(const char text1[], int8_t data, const char text2[]) override;
	void printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) override;
	void printIn(const char text[], int8_t x, int8_t y) override;
	void printIn(int8_t data, int8_t x, int8_t y) override;
	void showClock(MyDateTime timeIn) override;
	void blinkAt(int8_t x, int8_t y) override;
	void noBlink() override;
	void clockSym(bool state) override;
	void dropSym(bool state) override;
	void checkSym(bool state) override;

protected:
};

#endif//CLAYDISPLAY_HPP
