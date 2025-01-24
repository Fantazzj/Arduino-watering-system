#include "HwDisplay.hpp"

void HwDisplay::displayError1() {
	lcd->print("Err. string");
	lcd->setCursor(0, 1);
	lcd->print("too big");
}

void HwDisplay::arrangeWords(String text, String row[]) {
	String buffer = "";
	int8_t rowN = 0;

	if(text.charAt(text.length() - 1) != ' ') text += " ";
	for(uint8_t i = 0; i < text.length(); i++) {
		if(text.charAt(i) != ' ') buffer += text.charAt(i);
		else {
			if(row[rowN].length() + buffer.length() <= lenght) row[rowN] += (buffer + " ");
			else if(rowN + 1 < height) row[++rowN] += (buffer + " ");
			buffer = "";
		}
	}
}

void HwDisplay::printRows(String row[]) {
	for(int8_t rowN = 0; rowN < height; rowN++) {
		lcd->setCursor(0, rowN);
		myPrint(row[rowN]);
	}
}

void HwDisplay::myPrint(String text) {
	for(uint8_t chr = 0; chr < text.length(); chr++) {
		if(text.charAt(chr) == 'a' && text.charAt(chr + 1) == '\'') {
			lcd->write(myA);
			chr++;
		} else if(text.charAt(chr) == 'e' && text.charAt(chr + 1) == '\'') {
			lcd->write(myE);
			chr++;
		} else if(text.charAt(chr) == 'i' && text.charAt(chr + 1) == '\'') {
			lcd->write(myI);
			chr++;
		} else if(text.charAt(chr) == 'o' && text.charAt(chr + 1) == '\'') {
			lcd->write(myO);
			chr++;
		} else if(text.charAt(chr) == 'u' && text.charAt(chr + 1) == '\'') {
			lcd->write(myU);
			chr++;
		} else lcd->print(text.charAt(chr));
	}
}

String HwDisplay::arrangeDate(MyDateTime time) {
	String arrangedDate = "";
	String separator = "/";
	if(time.date.day < 10) arrangedDate += "0";
	arrangedDate += String(time.date.day);
	arrangedDate += separator;
	if(time.date.mon < 10) arrangedDate += "0";
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
	String separator = ":";
	if(time.time.hour < 10) arrangedTime += "0";
	arrangedTime += String(time.time.hour);
	arrangedTime += separator;
	if(time.time.min < 10) arrangedTime += "0";
	arrangedTime += String(time.time.min);
	return arrangedTime;
}

HwDisplay::HwDisplay(int8_t address, int8_t lenght, int8_t height) {
	lcd = new LiquidCrystal_I2C(address, lenght, height);
	lcdLenght = height * lenght;
	this->height = height;
	this->lenght = lenght;
}

void HwDisplay::begin() {
	lcd->init();
	lcd->backlight();
	lcd->createChar((byte) myA, (byte*) myAArray);
	lcd->createChar((byte) myE, (byte*) myEArray);
	lcd->createChar((byte) myI, (byte*) myIArray);
	lcd->createChar((byte) myO, (byte*) myOArray);
	lcd->createChar((byte) myU, (byte*) myUArray);
	lcd->createChar((byte) myDrop, (byte*) myDropArray);
	lcd->createChar((byte) myCheck, (byte*) myCheckArray);
	lcd->createChar((byte) myClock, (byte*) myClockArray);
	lcd->home();
}

void HwDisplay::printSimpleText(char text[]) {
	String rows[height];
	String conv(text);

	lcd->clear();

	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void HwDisplay::printData(char text1[], int8_t data, char text2[]) {
	String row[height];

	String conv1(text1);
	String conv2(text2);

	String conv = conv1 + " " + String(data) + " " + conv2;

	lcd->clear();
	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, row);
		printRows(row);
	} else displayError1();
}

void HwDisplay::printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) {
	String row[height];

	String conv1(text1);
	String conv2(text2);
	String conv3(text3);

	String conv = conv1 + " " + String(data1) + " " + conv2 + " " + String(data2) + " " + conv3;

	lcd->clear();
	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, row);
		printRows(row);
	} else displayError1();
}

void HwDisplay::printIn(char text[], int8_t col, int8_t row) {
	String conv(text);

	lcd->setCursor(col, row);
	myPrint(conv);
}

void HwDisplay::printIn(String text, int8_t col, int8_t row) {
	lcd->setCursor(col, row);
	myPrint(text);
}

void HwDisplay::printIn(int8_t num, int8_t col, int8_t row) {
	String conv = String(num);

	lcd->setCursor(col, row);
	myPrint(conv);
}

void HwDisplay::showClock(MyDateTime timeIn) {
	lcd->clear();
	String date;
	date = arrangeDate(timeIn);
	printIn(date, 0, 1);
	String dow;
	dow = arrangeDow(timeIn);
	printIn(dow, 0, 0);
	String time;
	time = arrangeTime(timeIn);
	printIn(time, 11, 0);
	//printIn(String(timeIn.sec),14,1);
}

void HwDisplay::blinkAt(int8_t x, int8_t y) {
	lcd->setCursor(x, y);
	lcd->blink();
}

void HwDisplay::noBlink() {
	lcd->noBlink();
}

void HwDisplay::clockSym(bool state) {
	lcd->setCursor(12, 1);
	if(state) lcd->write(myClock);
	else lcd->print(" ");
}

void HwDisplay::dropSym(bool state) {
	lcd->setCursor(13, 1);
	if(state) lcd->write(myDrop);
	else lcd->print(" ");
}

void HwDisplay::checkSym(bool state) {
	lcd->setCursor(14, 1);
	if(state) lcd->write(myCheck);
	else lcd->print(" ");
}

void HwDisplay::backlight(bool state) {
	UnitDisplay::backlight(state);
	if(state) lcd->backlight();
	else lcd->noBacklight();
}
