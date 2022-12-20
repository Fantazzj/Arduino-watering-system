#ifndef CLOCK_CPP
#define CLOCK_CPP

#include "MyTime.cpp"

class Clock {
private:
public:
	Clock() = default;
	virtual MyTime getTime() {
		MyTime null;
		return null;
	}
	virtual void setTime(MyTime time) {}

protected:
};

#endif//CLOCK_CPP
