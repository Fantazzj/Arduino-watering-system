#ifndef VALVE_HPP
#define VALVE_HPP

#include "Clock.hpp"
#include "MyTime.hpp"

class Valve {
private:
public:
	uint8_t days;
	uint8_t minOn;
	uint8_t elapsedDays = 1;
	MyTime tOn;

	Valve(Clock* etvClock, uint8_t minOn, uint8_t days);
	virtual void turnOn();
	virtual void turnOff() = 0;
	bool toWater();
	bool wateringDone(MyTime newTime);

protected:
	Clock* etvClock;
};

#endif//VALVE_HPP
