#ifndef QT_DISPLAY_CPP
#define QT_DISPLAY_CPP

#include "../core-lib/UnitDisplay.hpp"
#include "ControlUnit.h"

class QtDisplay : public UnitDisplay {
private:
	ControlUnit* _w;
	int8_t _length;
	int8_t _height;
	int8_t _displayChars;

	void _displayError1();
	void _arrangeWords(QString text, QString rows[]) const;
	void _printRows(QString rows[]);
	static QString _arrangeDate(MyDate time);
	static QString _arrangeDow(MyDate time);
	static QString _arrangeTime(MyTime time);

public:
	explicit QtDisplay();
	void begin(ControlUnit* w);
	void printSimpleText(char text[]) override;
	void printData(char text1[], int8_t data, char text2[]) override;
	void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) override;
	void printIn(char text[], int8_t x, int8_t y) override;
	void printIn(int8_t data, int8_t x, int8_t y) override;
	void printIn(QString text, int8_t x, int8_t y);
	void showClock(MyDateTime timeIn) override;
	void blinkAt(int8_t x, int8_t y) override;
	void noBlink() override;
	void clockSym(bool state) override;
	void dropSym(bool state) override;
	void checkSym(bool state) override;
	void backlight(bool state) override;
};

#endif
