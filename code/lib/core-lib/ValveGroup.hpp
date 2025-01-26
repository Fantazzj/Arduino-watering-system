#ifndef VALVEGROUP_HPP
#define VALVEGROUP_HPP

#include "../date-time-lib/MyTime.hpp"
#include "Clock.hpp"

template<uint8_t n>
class ValveGroup {
private:
public:
	ValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn, uint8_t* elapsedDays);
	void turnOn(uint8_t num) = 0;
	void turnOff(uint8_t num) = 0;
	bool toWater(uint8_t num) const;
	bool wateringDone(uint8_t num, MyTime newTime) const;

protected:
	Clock& clock;
	uint8_t days[n];
	uint8_t minOn[n];
	uint8_t elapsedDays[n];
	MyTime tOn[n];
};

#endif//VALVEGROUP_HPP
