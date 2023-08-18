#include "Valve.hpp"

Valve::Valve(Clock* etvClock, int8_t minOn, int8_t days) {
	this->etvClock = etvClock;
	this->minOn = minOn;
	this->days = days;
}
void Valve::turnOn() {
	tOn = etvClock->getTime();
	elapsedDays = 1;
}
void Valve::turnOff() {}
bool Valve::toWater() {
	if(elapsedDays >= days and days > 0 and minOn > 0) return true;
	else return false;
}
bool Valve::wateringDone(MyTime newTime) {
	if(MyTime::elapsedMin(tOn, newTime) >= minOn) return true;
	else return false;
}
