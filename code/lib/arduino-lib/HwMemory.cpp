#include "HwMemory.hpp"

HwMemory::HwMemory(int8_t etvNum) :
	Memory(etvNum) {}

void HwMemory::saveEtvMinOn(int8_t num, int8_t minOn) {
}

int8_t HwMemory::readEtvMinOn(int8_t num) {
	return 5;
}

void HwMemory::saveEtvDays(int8_t num, int8_t days) {
}

int8_t HwMemory::readEtvDays(int8_t num) {
	return 0;
}
