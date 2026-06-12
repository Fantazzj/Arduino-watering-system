#include "StdDisplay.hpp"

StdDisplay::StdDisplay() :
	text{}, blinkChar{-1, -1}, backlight{false}, x{}, y{} {}

void StdDisplay::printSimpleText(const char text[]) {
	std::string rows[DISPLAY_HEIGHT];
	const std::string conv(text);

	clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void StdDisplay::printData(const char text1[], const int8_t data, const char text2[]) {
	std::string rows[DISPLAY_HEIGHT];

	const std::string conv1(text1);
	const std::string conv2(text2);

	const std::string conv = conv1 + " " + std::to_string(data) + " " + conv2;

	clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void StdDisplay::printData(const char text1[], const int8_t data1, const char text2[], const int8_t data2, const char text3[]) {
	std::string rows[DISPLAY_HEIGHT];

	const std::string conv1(text1);
	const std::string conv2(text2);
	const std::string conv3(text3);

	const std::string conv = conv1 + " " + std::to_string(data1) + " " + conv2 + " " + std::to_string(data2) + " " + conv3;

	clearDisplay();

	if(conv.length() <= displayChars) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void StdDisplay::printIn(const char text[], const int8_t x, const int8_t y) {
	const std::string conv(text);

	setCursorDisplay(x, y);
	printOnDisplay(conv);
}

void StdDisplay::printIn(const int8_t data, const int8_t x, const int8_t y) {
	const std::string conv = std::to_string(data);

	setCursorDisplay(x, y);
	printOnDisplay(conv);
}

void StdDisplay::printIn(const std::string& data, const int8_t x, const int8_t y) {
	setCursorDisplay(x, y);
	printOnDisplay(data);
}

void StdDisplay::showClock(const MyDateTime timeIn) {
	clearDisplay();

	const std::string date = arrangeDate(timeIn.date);
	printIn(date, 0, 1);
	const std::string dow = arrangeDow(timeIn.date);
	printIn(dow, 0, 0);
	const std::string time = arrangeTime(timeIn.time);
	printIn(time, 11, 0);
}

void StdDisplay::blinkAt(const int8_t x, const int8_t y) {
	setCursorDisplay(x, y);
}

void StdDisplay::noBlink() {
	setCursorDisplay(-1, -1);
}

void StdDisplay::clockSym(const bool state) {
	setCursorDisplay(12, 1);
	printOnDisplay(state ? "c" : " ");
}

void StdDisplay::dropSym(const bool state) {
	setCursorDisplay(13, 1);
	printOnDisplay(state ? "d" : " ");
}

void StdDisplay::checkSym(const bool state) {
	setCursorDisplay(14, 1);
	printOnDisplay(state ? "c" : " ");
}

void StdDisplay::arrangeWords(std::string text, std::string rows[]) {
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

void StdDisplay::printRows(std::string rows[]) {
	for(int8_t row = 0; row < DISPLAY_HEIGHT; row++) {
		setCursorDisplay(0, row);
		printOnDisplay(rows[row]);
	}
}

std::string StdDisplay::arrangeDate(const MyDate time) {
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

std::string StdDisplay::arrangeDow(const MyDate time) {
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
			arrangedDow = "MissingDOW";
			break;
	}
	return arrangedDow;
}

std::string StdDisplay::arrangeTime(const MyTime time) {
	std::string arrangedTime;
	const std::string separator = ":";
	if(time.hour < 10) arrangedTime += "0";
	arrangedTime += std::to_string(time.hour);
	arrangedTime += separator;
	if(time.min < 10) arrangedTime += "0";
	arrangedTime += std::to_string(time.min);
	return arrangedTime;
}

void StdDisplay::displayError1() {
	printOnDisplay("Err. string");
	setCursorDisplay(0, 1);
	printOnDisplay("too big");
}

void StdDisplay::clearDisplay() {
	for(int8_t i = 0; i < DISPLAY_HEIGHT; i++)
		for(int8_t j = 0; j < DISPLAY_LENGTH; j++)
			text[i][j] = ' ';
}

void StdDisplay::printOnDisplay(string s) {
	for(int8_t i = x, j = 0; j < s.size() && i < DISPLAY_LENGTH; i++, j++) {
		text[y][i] = s[j];
	}
}

void StdDisplay::setCursorDisplay(int8_t x, int8_t y) {
	this->x = x;
	this->y = y;
}

void StdDisplay::setBacklight(const bool state) {
	backlight = state;
}

bool StdDisplay::getBacklight() const {
	return backlight;
}

int8_t* StdDisplay::getBlinkChar() {
	return blinkChar;
}

char* StdDisplay::getTextLine(const uint8_t n) {
	return text[n];
}
