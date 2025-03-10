#ifndef QT_DISPLAY_CPP
#define QT_DISPLAY_CPP

#include "../core-lib/UnitDisplay.hpp"
#include "QtControlUnit.hpp"

class QtDisplay : public UnitDisplay {
private:
	QtControlUnit* _w;
	int8_t _length;
	int8_t _height;
	int8_t _displayChars;
	bool _backlight;

	void _displayError1();
	void _arrangeWords(QString text, QString rows[]) const;
	void _printRows(QString rows[]);
	static QString _arrangeDate(MyDate time);
	static QString _arrangeDow(MyDate time);
	static QString _arrangeTime(MyTime time);

public:
	explicit QtDisplay();
	void begin(QtControlUnit* w);
	void printSimpleText(const char text[]) override;
	void printData(const char text1[], int8_t data, const char text2[]) override;
	void printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) override;
	void printIn(const char text[], int8_t x, int8_t y) override;
	void printIn(int8_t data, int8_t x, int8_t y) override;
	void printIn(QString text, int8_t x, int8_t y);
	void showClock(MyDateTime timeIn) override;
	void blinkAt(int8_t x, int8_t y) override;
	void noBlink() override;
	void clockSym(bool state) override;
	void dropSym(bool state) override;
	void checkSym(bool state) override;
	void setBacklight(bool state) override;
	[[nodiscard]] bool getBacklight() const override;
};

#endif
