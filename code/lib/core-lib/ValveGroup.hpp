#ifndef VALVEGROUP_HPP
#define VALVEGROUP_HPP

#include "../date-time-lib/MyTime.hpp"
#include "Clock.hpp"

template<uint8_t n>
class ValveGroup {
private:
public:
	explicit ValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn);
	explicit ValveGroup(Clock& clock);
	virtual void turnOn(uint8_t num) = 0;
	virtual void turnOff(uint8_t num) = 0;
	[[nodiscard]] bool toWater(uint8_t num) const;
	[[nodiscard]] bool wateringDone(uint8_t num, MyTime newTime) const;
	[[nodiscard]] uint8_t getDays(uint8_t i) const;
	void setDays(uint8_t i, uint8_t days);
	[[nodiscard]] uint8_t getMinOn(uint8_t i) const;
	void setMinOn(uint8_t i, uint8_t minOn);
	[[nodiscard]] MyTime getTOn(uint8_t i) const;

protected:
	Clock& clock;
	uint8_t days[n];
	uint8_t minOn[n];
	uint8_t elapsedDays[n];
	MyTime tOn[n];
};

#endif//VALVEGROUP_HPP
