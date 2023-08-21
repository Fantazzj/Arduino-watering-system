#include "UnitDisplay.hpp"

void UnitDisplay::printSimpleText(char text[]) {}
void UnitDisplay::printData(char text1[], int8_t data, char text2[]) {}
void UnitDisplay::printData(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) {}
void UnitDisplay::printIn(char text[], int8_t x, int8_t y) {}
void UnitDisplay::printIn(int8_t data, int8_t x, int8_t y) {}
void UnitDisplay::showClock(MyDateTime timeIn) {}
void UnitDisplay::blinkAt(int8_t x, int8_t y) {}
void UnitDisplay::noBlink() {}
void UnitDisplay::clockSym() {}
void UnitDisplay::noClockSym() {}
void UnitDisplay::dropSym() {}
void UnitDisplay::noDropSym() {}
void UnitDisplay::checkSym() {}
void UnitDisplay::noCheckSym() {}
void UnitDisplay::noSymbols() {
	noClockSym();
	noDropSym();
	noCheckSym();
}
void UnitDisplay::backlight() {}
void UnitDisplay::noBacklight() {}
