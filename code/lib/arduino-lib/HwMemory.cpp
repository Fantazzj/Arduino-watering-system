#include "HwMemory.hpp"
#include <EEPROM.h>

HwMemory::HwMemory(uint8_t etvNum) {
	_etvNum = etvNum;
}

void HwMemory::begin() {
	if(EEPROM[0x00] != 0) {
		uint8_t i;
		for(i = 0; i < 2 * (_etvNum + 1); i++)
			EEPROM.update(i, 0);

		EEPROM.update(i++, 0);
		EEPROM.update(i++, 30);
		EEPROM.update(i++, 0);
	}
}

void HwMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	EEPROM.update(num, minOn);
}

uint8_t HwMemory::readEtvMinOn(uint8_t num) {
	return EEPROM[num];
}

void HwMemory::saveEtvDays(uint8_t num, uint8_t days) {
	EEPROM.update(num + _etvNum + 1, days);
}

uint8_t HwMemory::readEtvDays(uint8_t num) {
	return EEPROM[num + _etvNum + 1];
}

void HwMemory::saveStartTime(MyTime startTime) {
	uint8_t i = 2 * _etvNum + 1 + 1;
	EEPROM.update(i++, startTime.hour);
	EEPROM.update(i++, startTime.min);
	EEPROM.update(i++, startTime.sec);
}

MyTime HwMemory::readStartTime() {
	MyTime out;
	uint8_t i = 2 * _etvNum + 1 + 1;

	out.hour = EEPROM[i++];
	out.min = EEPROM[i++];
	out.sec = EEPROM[i++];

	return out;
}
