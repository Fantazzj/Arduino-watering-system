#ifndef HWDISPLAY_CPP
#define HWDISPLAY_CPP

#include <LiquidCrystal_I2C.h>
#include "../core/UnitDisplay.hpp"
#include <Wire.h>

class HwDisplay : public UnitDisplay {
private:
	LiquidCrystal_I2C* lcd;
	const char myAArray[8] = {0x08, 0x04, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00};
	const char myA = 0;
	const char myEArray[8] = {0x08, 0x04, 0x0E, 0x11, 0x1E, 0x10, 0x0E, 0x00};
	const char myE = 1;
	const char myIArray[8] = {0x08, 0x04, 0x00, 0x0C, 0x04, 0x04, 0x0E, 0x00};
	const char myI = 2;
	const char myOArray[8] = {0x08, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00};
	const char myO = 3;
	const char myUArray[8] = {0x08, 0x04, 0x11, 0x11, 0x11, 0x13, 0x0D, 0x00};
	const char myU = 4;
	const char myDropArray[8] = {0x04, 0x0A, 0x0A, 0x13, 0x17, 0x1F, 0x0E, 0x00};
	const char myDrop = 5;
	const char myCheckArray[8] = {0x00, 0x00, 0x00, 0x01, 0x02, 0x14, 0x08, 0x00};
	const char myCheck = 6;
	const char myClockArray[8] = {0x00, 0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00};
	const char myClock = 7;
	uint8_t height = 0;
	uint8_t lenght = 0;
	uint8_t lcdLenght = 0;
	void displayError1();
	void arrangeWords(String text, String row[]);
	void printRows(String row[]);
	void myPrint(String text);
	String arrangeDate(MyDateTime time);
	String arrangeDow(MyDateTime time);
	String arrangeTime(MyDateTime time);

public:
	HwDisplay(int8_t address, int8_t lenght, int8_t height);
	void printSimpleText(char text[]) override;
	void printData(char text1[], int8_t data, char text2[]) override;
	void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) override;
	void printIn(char text[], int8_t col, int8_t row) override;
	void printIn(String text, int8_t col, int8_t row);
	void printIn(int8_t num, int8_t col, int8_t row) override;
	void showClock(MyDateTime timeIn) override;
	void blinkAt(int8_t x, int8_t y) override;
	void noBlink() override;
	void clockSym(bool state) override;
	void dropSym(bool state) override;
	void checkSym(bool state) override;
	void backlight(bool state) override;

protected:
};

#endif