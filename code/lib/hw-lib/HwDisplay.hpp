#ifndef HWDISPLAY_CPP
#define HWDISPLAY_CPP

#include "LiquidCrystal_I2C.h"
#include "../core/UnitDisplay.hpp"
#include <Wire.h>

class HwDisplay : public UnitDisplay {
private:
	LiquidCrystal_I2C* lcd;
	byte myAArray[8] = {0x08, 0x04, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00};
	byte myA = 0;
	byte myEArray[8] = {0x08, 0x04, 0x0E, 0x11, 0x1E, 0x10, 0x0E, 0x00};
	byte myE = 1;
	byte myIArray[8] = {0x08, 0x04, 0x00, 0x0C, 0x04, 0x04, 0x0E, 0x00};
	byte myI = 2;
	byte myOArray[8] = {0x08, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00};
	byte myO = 3;
	byte myUArray[8] = {0x08, 0x04, 0x11, 0x11, 0x11, 0x13, 0x0D, 0x00};
	byte myU = 4;
	byte myDropArray[8] = {0x04, 0x0A, 0x0A, 0x13, 0x17, 0x1F, 0x0E, 0x00};
	byte myDrop = 5;
	byte myCheckArray[8] = {0x00, 0x00, 0x00, 0x01, 0x02, 0x14, 0x08, 0x00};
	byte myCheck = 6;
	byte myClockArray[8] = {0x00, 0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00};
	byte myClock = 7;
	int8_t height = 0;
	int8_t lenght = 0;
	int8_t lcdLenght = 0;
	void displayError1();
	void arrangeWords(String text, String row[]);
	void printRows(String row[]);
	void myPrint(String text);
	String arrangeDate(MyTime time);
	String arrangeDow(MyTime time);
	String arrangeTime(MyTime time);

public:
	HwDisplay(int8_t address, int8_t lenght, int8_t height);
	void printSimpleText(char text[]);
	void printData(char text1[], int8_t data, char text2[]);
	void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]);
	void printIn(char text[], int8_t col, int8_t row);
	void printIn(String text, int8_t col, int8_t row);
	void printIn(int8_t num, int8_t col, int8_t row);
	void showClock(MyTime timeIn);
	void blinkAt(int8_t x, int8_t y);
	void noBlink();
	void clockSym();
	void noClockSym();
	void dropSym();
	void noDropSym();
	void checkSym();
	void noCheckSym();
	void noSymbols();
	void backlight();
	void noBacklight();

protected:
};

#endif