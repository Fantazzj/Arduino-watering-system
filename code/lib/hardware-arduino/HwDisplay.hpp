#ifndef HWDISPLAY_CPP
#define HWDISPLAY_CPP

#include "../core-lib/UnitDisplay.hpp"
#include <LiquidCrystal_I2C.h>

class HwDisplay : public UnitDisplay {
private:
	LiquidCrystal_I2C lcd;
	uint8_t height = 0;
	uint8_t lenght = 0;
	uint8_t lcdLenght = 0;
	bool backlight;

	void displayError1();
	void arrangeWords(String text, String row[]);
	void printRows(String row[]);
	void myPrint(String text);
	String arrangeDate(MyDateTime time);
	String arrangeDow(MyDateTime time);
	String arrangeTime(MyDateTime time);

public:
	explicit HwDisplay(int8_t address, int8_t lenght, int8_t height);
	void begin();
	void printSimpleText(const char text[]) override;
	void printData(const char text1[], int8_t data, const char text2[]) override;
	void printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) override;
	void printIn(const char text[], int8_t col, int8_t row) override;
	void printIn(String text, int8_t col, int8_t row);
	void printIn(int8_t num, int8_t col, int8_t row) override;
	void showClock(MyDateTime timeIn) override;
	void blinkAt(int8_t x, int8_t y) override;
	void noBlink() override;
	void clockSym(bool state) override;
	void dropSym(bool state) override;
	void checkSym(bool state) override;
	void setBacklight(bool state) override;
	bool getBacklight() const override;

protected:
};

#endif