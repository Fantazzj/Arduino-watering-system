#ifndef VALVE_HPP
#define VALVE_HPP

#include "../date-time/MyTime.hpp"
#include "Clock.hpp"

class Valve {
private:
public:
	uint8_t days;
	uint8_t minOn;
	uint8_t elapsedDays = 1;
	MyTime tOn;

	Valve(Clock& etvClock, uint8_t minOn, uint8_t days);
	virtual void turnOn();
	virtual void turnOff() = 0;
	bool toWater() const;
	bool wateringDone(MyTime newTime) const;

protected:
	Clock& etvClock;
};

#endif//VALVE_HPP
