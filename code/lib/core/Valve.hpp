#ifndef VALVE_HPP
#define VALVE_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "Clock.hpp"
#include "MyTime.hpp"

class Valve {
private:
public:
	int8_t days;
	int8_t minOn;
	int8_t elapsedDays = 1;
	MyTime tOn;

	Valve(Clock* etvClock, int8_t minOn, int8_t days);
	virtual void turnOn();
	virtual void turnOff();
	bool toWater();
	bool wateringDone(MyTime newTime);

protected:
	Clock* etvClock;
};

#endif//VALVE_HPP
