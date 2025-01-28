#include "HwValveGroup.hpp"

HwValveGroup::HwValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn, const int8_t* etvsPin) :
	ValveGroup(clock, days, minOn) {
	for(int8_t i = 0; i < VALVE_NUM; i++)
		this->etvsPin[i] = etvsPin[i];
}

HwValveGroup::HwValveGroup(Clock& clock, const int8_t* etvsPin) :
	ValveGroup(clock) {
	for(int8_t i = 0; i < VALVE_NUM; i++)
		this->etvsPin[i] = etvsPin[i];
}

void HwValveGroup::begin() {
	for(int8_t i = 0; i < VALVE_NUM; i++)
		pinMode(etvsPin[i], OUTPUT);
}

void HwValveGroup::turnOn(uint8_t i) {
	this->tOn[i] = this->clock.getTime().time;
	this->elapsedDays[i] = 1;
	digitalWrite(etvsPin[i], HIGH);
}

void HwValveGroup::turnOff(uint8_t i) {
	digitalWrite(etvsPin[i], LOW);
}
