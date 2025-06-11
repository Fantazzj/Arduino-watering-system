#include "HwDisplay.hpp"

HwDisplay::HwDisplay(int8_t address, int8_t lenght, int8_t height) :
	lcd(address, lenght, height) {
	lcdLenght = height * lenght;
	this->height = height;
	this->lenght = lenght;
}

#define myA 0
#define myE 1
#define myI 2
#define myO 3
#define myU 4
#define myDrop 5
#define myCheck 6
#define myClock 7

void HwDisplay::begin() {
	byte myAArray[8] = {0x08, 0x04, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00};
	byte myEArray[8] = {0x08, 0x04, 0x0E, 0x11, 0x1E, 0x10, 0x0E, 0x00};
	byte myIArray[8] = {0x08, 0x04, 0x00, 0x0C, 0x04, 0x04, 0x0E, 0x00};
	byte myOArray[8] = {0x08, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00};
	byte myUArray[8] = {0x08, 0x04, 0x11, 0x11, 0x11, 0x13, 0x0D, 0x00};
	byte myDropArray[8] = {0x04, 0x0A, 0x0A, 0x13, 0x17, 0x1F, 0x0E, 0x00};
	byte myCheckArray[8] = {0x00, 0x00, 0x00, 0x01, 0x02, 0x14, 0x08, 0x00};
	byte myClockArray[8] = {0x00, 0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00};
	lcd.init();
	lcd.backlight();
	lcd.createChar(myA, myAArray);
	lcd.createChar(myE, myEArray);
	lcd.createChar(myI, myIArray);
	lcd.createChar(myO, myOArray);
	lcd.createChar(myU, myUArray);
	lcd.createChar(myDrop, myDropArray);
	lcd.createChar(myCheck, myCheckArray);
	lcd.createChar(myClock, myClockArray);
	lcd.home();
}

void HwDisplay::displayError1() {
	lcd.print("Err. string");
	lcd.setCursor(0, 1);
	lcd.print("too big");
}

void HwDisplay::arrangeWords(String text, String row[]) {
	String buffer = "";
	int8_t rowN = 0;

	if(text.charAt(text.length() - 1) != ' ') text += ' ';
	for(uint8_t i = 0; i < text.length(); i++) {
		if(text.charAt(i) != ' ') buffer += text.charAt(i);
		else {
			if(row[rowN].length() + buffer.length() <= lenght) row[rowN] += (buffer + ' ');
			else if(rowN + 1 < height) row[++rowN] += (buffer + ' ');
			buffer = "";
		}
	}
}

void HwDisplay::printRows(String row[]) {
	for(int8_t rowN = 0; rowN < height; rowN++) {
		lcd.setCursor(0, rowN);
		myPrint(row[rowN]);
	}
}

void HwDisplay::myPrint(String text) {
	for(uint8_t chr = 0; chr < text.length(); chr++) {
		if(text.charAt(chr) == 'a' && text.charAt(chr + 1) == '\'') {
			lcd.write(myA);
			chr++;
		} else if(text.charAt(chr) == 'e' && text.charAt(chr + 1) == '\'') {
			lcd.write(myE);
			chr++;
		} else if(text.charAt(chr) == 'i' && text.charAt(chr + 1) == '\'') {
			lcd.write(myI);
			chr++;
		} else if(text.charAt(chr) == 'o' && text.charAt(chr + 1) == '\'') {
			lcd.write(myO);
			chr++;
		} else if(text.charAt(chr) == 'u' && text.charAt(chr + 1) == '\'') {
			lcd.write(myU);
			chr++;
		} else lcd.print(text.charAt(chr));
	}
}

String HwDisplay::arrangeDate(MyDateTime time) {
	String arrangedDate = "";
	char separator = '/';
	if(time.date.day < 10) arrangedDate += '0';
	arrangedDate += String(time.date.day);
	arrangedDate += separator;
	if(time.date.mon < 10) arrangedDate += '0';
	arrangedDate += String(time.date.mon);
	arrangedDate += separator;
	arrangedDate += String(time.date.year);
	return arrangedDate;
}

String HwDisplay::arrangeDow(MyDateTime time) {
	String arrangedDow = "";
	switch(time.date.dow) {
		case Monday:
			arrangedDow = "Lunedi'";
			break;
		case Tuesday:
			arrangedDow = "Martedi'";
			break;
		case Wednesday:
			arrangedDow = "Mercoledi'";
			break;
		case Thursday:
			arrangedDow = "Giovedi'";
			break;
		case Friday:
			arrangedDow = "Venerdi'";
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

String HwDisplay::arrangeTime(MyDateTime time) {
	String arrangedTime = "";
	char separator = ':';
	if(time.time.hour < 10) arrangedTime += '0';
	arrangedTime += String(time.time.hour);
	arrangedTime += separator;
	if(time.time.min < 10) arrangedTime += '0';
	arrangedTime += String(time.time.min);
	return arrangedTime;
}

void HwDisplay::printSimpleText(const char text[]) {
	String rows[height];
	String conv(text);

	lcd.clear();

	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void HwDisplay::printData(const char text1[], int8_t data, const char text2[]) {
	String row[height];

	String conv = String(text1) + ' ' + String(data) + ' ' + String(text2);

	lcd.clear();
	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, row);
		printRows(row);
	} else displayError1();
}

void HwDisplay::printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) {
	String row[height];

	String conv = String(text1) + ' ' + String(data1) + ' ' + String(text2) + ' ' + String(data2) + ' ' + String(text3);

	lcd.clear();
	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, row);
		printRows(row);
	} else displayError1();
}

void HwDisplay::printIn(const char text[], int8_t col, int8_t row) {
	String conv(text);

	lcd.setCursor(col, row);
	myPrint(conv);
}

void HwDisplay::printIn(String text, int8_t col, int8_t row) {
	lcd.setCursor(col, row);
	myPrint(text);
}

void HwDisplay::printIn(int8_t num, int8_t col, int8_t row) {
	String conv = String(num);

	lcd.setCursor(col, row);
	myPrint(conv);
}

void HwDisplay::showClock(MyDateTime timeIn) {
	lcd.clear();
	String date;
	date = arrangeDate(timeIn);
	printIn(date, 0, 1);
	String dow;
	dow = arrangeDow(timeIn);
	printIn(dow, 0, 0);
	String time;
	time = arrangeTime(timeIn);
	printIn(time, 11, 0);
}

void HwDisplay::blinkAt(int8_t x, int8_t y) {
	lcd.setCursor(x, y);
	lcd.blink();
}

void HwDisplay::noBlink() {
	lcd.noBlink();
}

void HwDisplay::clockSym(bool state) {
	lcd.setCursor(12, 1);
	if(state) lcd.write(myClock);
	else lcd.print(' ');
}

void HwDisplay::dropSym(bool state) {
	lcd.setCursor(13, 1);
	if(state) lcd.write(myDrop);
	else lcd.print(' ');
}

void HwDisplay::checkSym(bool state) {
	lcd.setCursor(14, 1);
	if(state) lcd.write(myCheck);
	else lcd.print(' ');
}

void HwDisplay::setBacklight(bool state) {
	backlight = state;
	if(state) lcd.backlight();
	else lcd.noBacklight();
}

bool HwDisplay::getBacklight() const {
	return backlight;
}
