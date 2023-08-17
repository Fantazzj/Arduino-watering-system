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
	for(int8_t i = 0; i < text.length(); i++) {
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
	for(int8_t chr = 0; chr < text.length(); chr++) {
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

String HwDisplay::arrangeDate(MyTime time) {
	String arrangedDate = "";
	String separator = "/";
	if(time.date < 10) arrangedDate += "0";
	arrangedDate += String(time.date);
	arrangedDate += separator;
	if(time.mon < 10) arrangedDate += "0";
	arrangedDate += String(time.mon);
	arrangedDate += separator;
	arrangedDate += String(time.year);
	return arrangedDate;
}

String HwDisplay::arrangeDow(MyTime time) {
	String arrangedDow = "";
	switch(time.dow) {
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

String HwDisplay::arrangeTime(MyTime time) {
	String arrangedTime = "";
	String separator = ":";
	if(time.hour < 10) arrangedTime += "0";
	arrangedTime += String(time.hour);
	arrangedTime += separator;
	if(time.min < 10) arrangedTime += "0";
	arrangedTime += String(time.min);
	return arrangedTime;
}

HwDisplay::HwDisplay(int8_t address, int8_t lenght, int8_t height) {
	lcd = new LiquidCrystal_I2C(address, lenght, height);
	lcdLenght = height * lenght;
	this->height = height;
	this->lenght = lenght;
	lcd->init();
	lcd->backlight();
	lcd->createChar(myA, myAArray);
	lcd->createChar(myE, myEArray);
	lcd->createChar(myI, myIArray);
	lcd->createChar(myO, myOArray);
	lcd->createChar(myU, myUArray);
	lcd->createChar(myDrop, myDropArray);
	lcd->createChar(myCheck, myCheckArray);
	lcd->createChar(myClock, myClockArray);
	lcd->home();
}

void HwDisplay::printSimpleText(char text[]) {
	String rows[height];
	String conv = MyString::toArduinoString(text);

	lcd->clear();

	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, rows);
		printRows(rows);
	} else displayError1();
}

void HwDisplay::printData(char text1[], int8_t data, char text2[]) {
	String row[height];

	String conv1 = MyString::toArduinoString(text1);
	String conv2 = MyString::toArduinoString(text2);

	String conv = conv1 + " " + String(data) + " " + conv2;

	lcd->clear();
	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, row);
		printRows(row);
	} else displayError1();
}

void HwDisplay::printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) {
	String row[height];

	String conv1 = MyString::toArduinoString(text1);
	String conv2 = MyString::toArduinoString(text2);
	String conv3 = MyString::toArduinoString(text3);

	String conv = conv1 + " " + String(data1) + " " + conv2 + " " + String(data2) + " " + conv3;

	lcd->clear();
	if(conv.length() <= lcdLenght) {
		arrangeWords(conv, row);
		printRows(row);
	} else displayError1();
}

void HwDisplay::printIn(char text[], int8_t col, int8_t row) {
	String conv = MyString::toArduinoString(text);

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

void HwDisplay::showClock(MyTime timeIn) {
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

void HwDisplay::clockSym() {
	lcd->setCursor(12, 1);
	lcd->write(myClock);
}

void HwDisplay::noClockSym() {
	lcd->setCursor(12, 1);
	lcd->print(" ");
}

void HwDisplay::dropSym() {
	lcd->setCursor(13, 1);
	lcd->write(myDrop);
}

void HwDisplay::noDropSym() {
	lcd->setCursor(13, 1);
	lcd->print(" ");
}

void HwDisplay::checkSym() {
	lcd->setCursor(14, 1);
	lcd->write(myCheck);
}

void HwDisplay::noCheckSym() {
	lcd->setCursor(14, 1);
	lcd->print(" ");
}

void HwDisplay::noSymbols() {
	noClockSym();
	noDropSym();
	noCheckSym();
}

void HwDisplay::backlight() {
	lcd->backlight();
}

void HwDisplay::noBacklight() {
	lcd->noBacklight();
}
