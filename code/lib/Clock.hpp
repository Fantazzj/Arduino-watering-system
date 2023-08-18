#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "MyTime.hpp"

class Clock {
private:
public:
	Clock() = default;
	virtual MyTime getTime();
	virtual void setTime(MyTime time);

protected:
};

#endif//CLOCK_HPP
