#include "ValveGroup.hpp"

template<uint8_t n>
ValveGroup<n>::ValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn) :
	clock(clock) {
	for(uint8_t i = 0; i < n; i++) {
		this->days[i] = days[i];
		this->minOn[i] = minOn[i];
		this->elapsedDays[i] = 1;
	}
}

template<uint8_t n>
ValveGroup<n>::ValveGroup(Clock& clock) :
	clock(clock) {
	for(uint8_t i = 0; i < n; i++) {
		this->days[i] = 1;
		this->minOn[i] = 0;
		this->elapsedDays[i] = 1;
	}
}

template<uint8_t n>
bool ValveGroup<n>::toWater(uint8_t num) const {
	return (elapsedDays[num] >= days[num] && days[num] > 0 && minOn[num] > 0);
}

template<uint8_t n>
bool ValveGroup<n>::wateringDone(uint8_t num, MyTime newTime) const {
	return (secToMin(newTime - tOn[num]) >= minOn[num]);
}

template<uint8_t n>
MyTime ValveGroup<n>::getTOn(uint8_t i) const {
	return tOn[i];
}

template<uint8_t n>
void ValveGroup<n>::setMinOn(uint8_t i, uint8_t minOn) {
	this->minOn[i] = minOn;
}

template<uint8_t n>
uint8_t ValveGroup<n>::getMinOn(uint8_t i) const {
	return this->minOn[i];
}

template<uint8_t n>
void ValveGroup<n>::setDays(uint8_t i, uint8_t days) {
	this->days[i] = days;
}

template<uint8_t n>
uint8_t ValveGroup<n>::getDays(uint8_t i) const {
	return this->days[i];
}
