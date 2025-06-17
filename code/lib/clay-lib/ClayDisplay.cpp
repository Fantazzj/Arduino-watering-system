#include "ClayDisplay.hpp"

ClayDisplay::ClayDisplay() {
	w = nullptr;
	backlight = false;
}

void ClayDisplay::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayDisplay::printSimpleText(const char text[]) {
	std::string rows[DISPLAY_HEIGHT];
	const std::string conv(text);

	w->clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void ClayDisplay::printData(const char text1[], const int8_t data, const char text2[]) {
	std::string rows[DISPLAY_HEIGHT];

	const std::string conv1(text1);
	const std::string conv2(text2);

	const std::string conv = conv1 + " " + std::to_string(data) + " " + conv2;

	w->clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void ClayDisplay::printData(const char text1[], const int8_t data1, const char text2[], const int8_t data2, const char text3[]) {
	std::string rows[DISPLAY_HEIGHT];

	const std::string conv1(text1);
	const std::string conv2(text2);
	const std::string conv3(text3);

	const std::string conv = conv1 + " " + std::to_string(data1) + " " + conv2 + " " + std::to_string(data2) + " " + conv3;

	w->clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void ClayDisplay::printIn(const char text[], const int8_t x, const int8_t y) {
	const std::string conv(text);

	w->setCursorDisplay(x, y);
	w->printOnDisplay(conv);
}

void ClayDisplay::printIn(const int8_t data, const int8_t x, const int8_t y) {
	const std::string conv = std::to_string(data);

	w->setCursorDisplay(x, y);
	w->printOnDisplay(conv);
}

void ClayDisplay::printIn(const std::string& data, const int8_t x, const int8_t y) {
	w->setCursorDisplay(x, y);
	w->printOnDisplay(data);
}

void ClayDisplay::showClock(const MyDateTime timeIn) {
	w->clearDisplay();

	const std::string date = arrangeDate(timeIn.date);
	printIn(date, 0, 1);
	const std::string dow = arrangeDow(timeIn.date);
	printIn(dow, 0, 0);
	const std::string time = arrangeTime(timeIn.time);
	printIn(time, 11, 0);
}

void ClayDisplay::blinkAt(const int8_t x, const int8_t y) {
	w->hideCursorDisplay();
	w->setCursorDisplay(x, y);
	w->showCursorDisplay();
}

void ClayDisplay::noBlink() {
	w->hideCursorDisplay();
}

void ClayDisplay::clockSym(const bool state) {
	w->setCursorDisplay(12, 1);
	if(state) w->printOnDisplay("c");
	else w->printOnDisplay(" ");
}

void ClayDisplay::dropSym(const bool state) {
	w->setCursorDisplay(13, 1);
	if(state) w->printOnDisplay("d");
	else w->printOnDisplay(" ");
}

void ClayDisplay::checkSym(const bool state) {
	w->setCursorDisplay(14, 1);
	if(state) w->printOnDisplay("c");
	else w->printOnDisplay(" ");
}

void ClayDisplay::arrangeWords(std::string text, std::string rows[]) {
	std::string buffer;
	int8_t row = 0;

	if(!text.ends_with(' ')) text += " ";

	for(int64_t i = 0; i < text.length(); i++) {
		if(text[i] != ' ') buffer += text[i];
		else {
			if(rows[row].length() + buffer.length() <= DISPLAY_LENGTH) rows[row] += (buffer + " ");
			else if(row + 1 <= DISPLAY_HEIGHT) rows[++row] += (buffer + " ");
			buffer.clear();
		}
	}
}

void ClayDisplay::printRows(std::string rows[]) {
	for(int8_t row = 0; row < DISPLAY_HEIGHT; row++) {
		w->setCursorDisplay(0, row);
		w->printOnDisplay(rows[row]);
	}
}

std::string ClayDisplay::arrangeDate(const MyDate time) {
	std::string arrangedDate;
	const std::string separator = "/";
	if(time.day < 10) arrangedDate += "0";
	arrangedDate += std::to_string(time.day);
	arrangedDate += separator;
	if(time.mon < 10) arrangedDate += "0";
	arrangedDate += std::to_string(time.mon);
	arrangedDate += separator;
	arrangedDate += std::to_string(time.year);
	return arrangedDate;
}

std::string ClayDisplay::arrangeDow(const MyDate time) {
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
		default:
			arrangedDow = "DOW";
			break;
			;
	}
	return arrangedDow;
}

std::string ClayDisplay::arrangeTime(const MyTime time) {
	std::string arrangedTime;
	const std::string separator = ":";
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

void ClayDisplay::setBacklight(const bool state) {
	backlight = state;
}

bool ClayDisplay::getBacklight() const {
	return backlight;
}

