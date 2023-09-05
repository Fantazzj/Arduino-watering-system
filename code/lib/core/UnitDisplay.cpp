#include "UnitDisplay.hpp"

void UnitDisplay::printSimpleText(char text[]) {}
void UnitDisplay::printData(char text1[], int8_t data, char text2[]) {}
void UnitDisplay::printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) {}
void UnitDisplay::printIn(char text[], int8_t x, int8_t y) {}
void UnitDisplay::printIn(int8_t data, int8_t x, int8_t y) {}
void UnitDisplay::showClock(MyDateTime timeIn) {}
void UnitDisplay::blinkAt(int8_t x, int8_t y) {}
void UnitDisplay::noBlink() {}
void UnitDisplay::clockSym(bool state) {}
void UnitDisplay::dropSym(bool state) {}
void UnitDisplay::checkSym(bool state) {}
void UnitDisplay::backlight(bool state) {
	backlightState = state;
}
bool UnitDisplay::getBacklight() {
	return backlightState;
}
