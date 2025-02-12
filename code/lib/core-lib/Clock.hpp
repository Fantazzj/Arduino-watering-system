#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "../date-time-lib/MyDateTime.hpp"

class Clock {
private:
public:
	virtual MyDateTime getDateTime() = 0;
	virtual void setDateTime(MyDateTime time) = 0;

protected:
};

#endif//CLOCK_HPP
