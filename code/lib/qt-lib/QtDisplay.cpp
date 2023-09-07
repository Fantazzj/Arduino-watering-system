#include "QtDisplay.hpp"

void QtDisplay::_displayError1() {
	_w->printOnDisplay("Err. string");
	_w->setCursorDisplay(0, 1);
	_w->printOnDisplay("too big");
}

void QtDisplay::_arrangeWords(QString text, QString rows[]) {
	QString buffer = "";
	int8_t row = 0;

	if(!text.endsWith(' ')) text += " ";

	for(int64_t i = 0; i < text.length(); i++) {
		if(text.data()[i] != ' ') buffer += text.data()[i];
		else {
			if(rows[row].length() + buffer.length() <= _length) rows[row] += (buffer + " ");
			else if(row + 1 <= _height) rows[++row] += (buffer + " ");
			buffer.clear();
		}
	}
}

void QtDisplay::_printRows(QString rows[]) {
	for(int8_t row = 0; row < _height; row++) {
		_w->setCursorDisplay(0, row);
		_w->printOnDisplay(rows[row]);
	}
}

QString QtDisplay::_arrangeDate(MyDate time) {
	QString arrangedDate = "";
	QString separator = "/";
	if(time.day < 10) arrangedDate += "0";
	arrangedDate += QString::number(time.day);
	arrangedDate += separator;
	if(time.mon < 10) arrangedDate += "0";
	arrangedDate += QString::number(time.mon);
	arrangedDate += separator;
	arrangedDate += QString::number(time.year);
	return arrangedDate;
}

QString QtDisplay::_arrangeDow(MyDate time) {
	QString arrangedDow = "";
	switch(time.dow) {
		case Monday:
			arrangedDow = "Lunedì";
			break;
		case Tuesday:
			arrangedDow = "Martedì";
			break;
		case Wednesday:
			arrangedDow = "Mercoledì";
			break;
		case Thursday:
			arrangedDow = "Giovedì";
			break;
		case Friday:
			arrangedDow = "Venerdì";
			break;
		case Saturday:
			arrangedDow = "Sabato";
			break;
		case Sunday:
			arrangedDow = "Domenica";
			break;
	}
	return arrangedDow;
}

QString QtDisplay::_arrangeTime(MyTime time) {
	QString arrangedTime = "";
	QString separator = ":";
	if(time.hour < 10) arrangedTime += "0";
	arrangedTime += QString::number(time.hour);
	arrangedTime += separator;
	if(time.min < 10) arrangedTime += "0";
	arrangedTime += QString::number(time.min);
	return arrangedTime;
}

QtDisplay::QtDisplay(ControlUnit* w) {
	this->_w = w;
	this->_length = w->getLength();
	this->_height = w->getHeight();
	_displayChars = _length * _height;
	w->backlight();
}

void QtDisplay::printSimpleText(char text[]) {
	QString rows[_height];
	QString conv;

	conv = MyString::toQString(text);

	_w->clearDisplay();

	if(conv.length() <= _displayChars) {
		_arrangeWords(conv, rows);
		_printRows(rows);
	} else _displayError1();
}

void QtDisplay::printData(char text1[], int8_t data, char text2[]) {
	QString rows[_height];

	QString conv1 = MyString::toQString(text1);
	QString conv2 = MyString::toQString(text2);

	QString conv = conv1 + " " + QString::number(data) + " " + conv2;

	_w->clearDisplay();

	if(conv.length() <= _displayChars) {
		_arrangeWords(conv, rows);
		_printRows(rows);
	} else _displayError1();
}

void QtDisplay::printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) {
	QString rows[_height];

	QString conv1 = MyString::toQString(text1);
	QString conv2 = MyString::toQString(text2);
	QString conv3 = MyString::toQString(text3);

	QString conv = conv1 + " " + QString::number(data1) + " " + conv2 + " " + QString::number(data2) + " " + conv3;

	_w->clearDisplay();

	if(conv.length() <= _displayChars) {
		_arrangeWords(conv, rows);
		_printRows(rows);
	} else _displayError1();
}

void QtDisplay::printIn(char text[], int8_t x, int8_t y) {
	QString conv = MyString::toQString(text);

	_w->setCursorDisplay(x, y);
	_w->printOnDisplay(conv);
}

void QtDisplay::printIn(int8_t data, int8_t x, int8_t y) {
	QString conv = QString::number(data);

	_w->setCursorDisplay(x, y);
	_w->printOnDisplay(conv);
}

void QtDisplay::printIn(QString text, int8_t x, int8_t y) {
	_w->setCursorDisplay(x, y);
	_w->printOnDisplay(text);
}

void QtDisplay::showClock(MyDateTime timeIn) {
	_w->clearDisplay();

	QString date;
	date = _arrangeDate(timeIn.date);
	printIn(date, 0, 1);
	QString dow;
	dow = _arrangeDow(timeIn.date);
	printIn(dow, 0, 0);
	QString time;
	time = _arrangeTime(timeIn.time);
	printIn(time, 11, 0);
	//printIn(QString::number(timeIn.sec),14,1);
}

void QtDisplay::blinkAt(int8_t x, int8_t y) {
	_w->hideCursorDisplay();
	_w->setCursorDisplay(x, y);
	_w->showCursorDisplay();
}

void QtDisplay::noBlink() {
	_w->hideCursorDisplay();
}

void QtDisplay::clockSym(bool state) {
	_w->setCursorDisplay(12, 1);
	if(state) _w->printOnDisplay("c");
	else _w->printOnDisplay(" ");
}

void QtDisplay::dropSym(bool state) {
	_w->setCursorDisplay(13, 1);
	if(state) _w->printOnDisplay("d");
	else _w->printOnDisplay(" ");
}

void QtDisplay::checkSym(bool state) {
	_w->setCursorDisplay(14, 1);
	if(state) _w->printOnDisplay("c");
	else _w->printOnDisplay(" ");
}

void QtDisplay::backlight(bool state) {
	UnitDisplay::backlight(state);
	if(state) _w->backlight();
	else _w->noBacklight();
}
