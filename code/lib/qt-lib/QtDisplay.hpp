#ifndef QT_DISPLAY_CPP
#	define QT_DISPLAY_CPP

#	include "ControlUnit.h"
#	include "../core/UnitDisplay.hpp"

class QtDisplay : public UnitDisplay {
private:
	ControlUnit* _w;
	int8_t _length;
	int8_t _height;
	int8_t _displayChars;

	void _displayError1();
	void _arrangeWords(QString text, QString rows[]);
	void _printRows(QString rows[]);
	QString _arrangeDate(MyDate time);
	QString _arrangeDow(MyDate time);
	QString _arrangeTime(MyTime time);

public:
	QtDisplay(ControlUnit* w, int8_t length, int8_t height);
	void printSimpleText(char text[]);
	void printData(char text1[], int8_t data, char text2[]);
	void printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]);
	void printIn(char text[], int8_t x, int8_t y);
	void printIn(int8_t data, int8_t x, int8_t y);
	void printIn(QString text, int8_t x, int8_t y);
	void showClock(MyDateTime timeIn);
	void blinkAt(int8_t x, int8_t y);
	void noBlink();
	void clockSym();
	void noClockSym();
	void dropSym();
	void noDropSym();
	void checkSym();
	void noCheckSym();
	void backlight();
	void noBacklight();
};

#endif
