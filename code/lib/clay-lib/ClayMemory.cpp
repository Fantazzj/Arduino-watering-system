#include "ClayMemory.hpp"

ClayMemory::ClayMemory(uint8_t etvNum) :
	Memory(etvNum) {
	//TODO: add definition
}

void ClayMemory::begin() {
}

void ClayMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	//TODO: add definition
}

uint8_t ClayMemory::readEtvMinOn(uint8_t num) {
	//TODO: add definition
	return 0;
}

void ClayMemory::saveEtvDays(uint8_t num, uint8_t days) {
	//TODO: add definition
}

uint8_t ClayMemory::readEtvDays(uint8_t num) {
	//TODO: add definition
	return 0;
}

void ClayMemory::saveStartTime(MyTime startTime) {
	//TODO: add definition
}

MyTime ClayMemory::readStartTime() {
	//TODO: add definition
	return MyTime();
}
