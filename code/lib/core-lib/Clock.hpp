#ifndef CLOCK_HPP
#define CLOCK_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "../date-time-lib/MyDateTime.hpp"

class Clock {
private:
public:
	explicit Clock() = default;
	virtual MyDateTime getTime() = 0;
	virtual void setTime(MyDateTime time) = 0;

protected:
};

#endif//CLOCK_HPP
