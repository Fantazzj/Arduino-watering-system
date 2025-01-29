#include "ClayDisplay.hpp"

ClayDisplay::ClayDisplay() {
	//TODO: add definition
}

void ClayDisplay::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayDisplay::printSimpleText(const char text[]) {
	//TODO: add definition
}

void ClayDisplay::printData(const char text1[], int8_t data, const char text2[]) {
	//TODO: add definition
}

void ClayDisplay::printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) {
	//TODO: add definition
}

void ClayDisplay::printIn(const char text[], int8_t x, int8_t y) {
	//TODO: add definition
}

void ClayDisplay::printIn(int8_t data, int8_t x, int8_t y) {
	//TODO: add definition
}

void ClayDisplay::showClock(MyDateTime timeIn) {
	//TODO: add definition
}

void ClayDisplay::blinkAt(int8_t x, int8_t y) {
	//TODO: add definition
}

void ClayDisplay::noBlink() {
	//TODO: add definition
}

void ClayDisplay::clockSym(bool state) {
	//TODO: add definition
}

void ClayDisplay::dropSym(bool state) {
	//TODO: add definition
}

void ClayDisplay::checkSym(bool state) {
	//TODO: add definition
}
