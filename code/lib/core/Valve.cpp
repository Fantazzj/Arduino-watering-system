#include "Valve.hpp"

Valve::Valve(Clock* etvClock, uint8_t minOn, uint8_t days) {
	this->etvClock = etvClock;
	this->minOn = minOn;
	this->days = days;
}
void Valve::turnOn() {
	tOn = etvClock->getTime().time;
	elapsedDays = 1;
}
bool Valve::toWater() {
	if(elapsedDays >= days && days > 0 && minOn > 0) return true;
	else return false;
}
bool Valve::wateringDone(MyTime newTime) {
	if( secToMin(newTime-tOn) >= minOn) return true;
	else return false;
}
