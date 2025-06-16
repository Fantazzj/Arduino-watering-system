#include "ClayDisplay.hpp"

ClayDisplay::ClayDisplay() {
	w = nullptr;
	height = 2;
	length = 16;
	displayChars = height * length;
}

void ClayDisplay::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayDisplay::printSimpleText(const char text[]) {
	std::string rows[height];
	const std::string conv(text);

	w->clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void ClayDisplay::printData(const char text1[], const int8_t data, const char text2[]) {
	std::string rows[height];

	const std::string conv1(text1);
	const std::string conv2(text2);

	const std::string conv = conv1 + " " + std::to_string(data) + " " + conv2;

	w->clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void ClayDisplay::printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) {
	std::string rows[height];

	std::string conv1(text1);
	std::string conv2(text2);
	std::string conv3(text3);

	std::string conv = conv1 + " " + std::to_string(data1) + " " + conv2 + " " + std::to_string(data2) + " " + conv3;

	w->clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void ClayDisplay::printIn(const char text[], int8_t x, int8_t y) {
	std::string conv(text);

	w->setCursorDisplay(x, y);
	w->printOnDisplay(conv);
}

void ClayDisplay::printIn(int8_t data, int8_t x, int8_t y) {
	std::string conv = std::to_string(data);

	w->setCursorDisplay(x, y);
	w->printOnDisplay(conv);
}

void ClayDisplay::printIn(std::string text, int8_t x, int8_t y) {
	w->setCursorDisplay(x, y);
	w->printOnDisplay(text);
}

void ClayDisplay::showClock(MyDateTime timeIn) {
	w->clearDisplay();

	std::string date;
	date = arrangeDate(timeIn.date);
	printIn(date, 0, 1);
	std::string dow;
	dow = arrangeDow(timeIn.date);
	printIn(dow, 0, 0);
	std::string time;
	time = arrangeTime(timeIn.time);
	printIn(time, 11, 0);
}

void ClayDisplay::blinkAt(int8_t x, int8_t y) {
	w->hideCursorDisplay();
	w->setCursorDisplay(x, y);
	w->showCursorDisplay();
}

void ClayDisplay::noBlink() {
	w->hideCursorDisplay();
}

void ClayDisplay::clockSym(bool state) {
	w->setCursorDisplay(12, 1);
	if(state) w->printOnDisplay("c");
	else w->printOnDisplay(" ");
}

void ClayDisplay::dropSym(bool state) {
	w->setCursorDisplay(13, 1);
	if(state) w->printOnDisplay("d");
	else w->printOnDisplay(" ");
}

void ClayDisplay::checkSym(bool state) {
	w->setCursorDisplay(14, 1);
	if(state) w->printOnDisplay("c");
	else w->printOnDisplay(" ");
}

void ClayDisplay::arrangeWords(std::string text, std::string rows[]) const {
	std::string buffer;
	int8_t row = 0;

	if(!text.ends_with(' ')) text += " ";

	for(int64_t i = 0; i < text.length(); i++) {
		if(text[i] != ' ') buffer += text[i];
		else {
			if(rows[row].length() + buffer.length() <= length) rows[row] += (buffer + " ");
			else if(row + 1 <= height) rows[++row] += (buffer + " ");
			buffer.clear();
		}
	}
}

void ClayDisplay::printRows(std::string rows[]) {
	for(int8_t row = 0; row < height; row++) {
		w->setCursorDisplay(0, row);
		w->printOnDisplay(rows[row]);
	}
}

std::string ClayDisplay::arrangeDate(MyDate time) {
	std::string arrangedDate;
	std::string separator = "/";
	if(time.day < 10) arrangedDate += "0";
	arrangedDate += std::to_string(time.day);
	arrangedDate += separator;
	if(time.mon < 10) arrangedDate += "0";
	arrangedDate += std::to_string(time.mon);
	arrangedDate += separator;
	arrangedDate += std::to_string(time.year);
	return arrangedDate;
}

std::string ClayDisplay::arrangeDow(MyDate time) {
	std::string arrangedDow;
	switch(time.dow) {
		case Monday:
			arrangedDow = "Lunedi";
			break;
		case Tuesday:
			arrangedDow = "Martedi";
			break;
		case Wednesday:
			arrangedDow = "Mercoledi";
			break;
		case Thursday:
			arrangedDow = "Giovedi";
			break;
		case Friday:
			arrangedDow = "Venerdi";
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

std::string ClayDisplay::arrangeTime(MyTime time) {
	std::string arrangedTime;
	std::string separator = ":";
	if(time.hour < 10) arrangedTime += "0";
	arrangedTime += std::to_string(time.hour);
	arrangedTime += separator;
	if(time.min < 10) arrangedTime += "0";
	arrangedTime += std::to_string(time.min);
	return arrangedTime;
}

void ClayDisplay::displayError1() {
	w->printOnDisplay("Err. string");
	w->setCursorDisplay(0, 1);
	w->printOnDisplay("too big");
}

void ClayDisplay::setBacklight(bool state) {
	backlight = state;
}

bool ClayDisplay::getBacklight() const {
	return backlight;
}

