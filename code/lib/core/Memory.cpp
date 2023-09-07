#include "Memory.hpp"

Memory::Memory(uint8_t etvNum) {
	_etvNum = etvNum;
}

void Memory::saveEtvMinOn(uint8_t num, uint8_t minOn) {}
uint8_t Memory::readEtvMinOn(uint8_t num) { return 0; }
void Memory::saveEtvDays(uint8_t num, uint8_t days) {}
uint8_t Memory::readEtvDays(uint8_t num) { return 0; }
void Memory::saveStartTime(MyTime startTime) {}
MyTime Memory::readStartTime() {
	return {0, 30, 0};
}
