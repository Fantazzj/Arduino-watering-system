#ifndef QT_CLOCK_CPP
#define QT_CLOCK_CPP

#include "lib/Clock.hpp"
#include "../ControlUnit.h"
#include <QString>

class QtClock : public Clock {
private:
	ControlUnit* _w;

public:
	QtClock(ControlUnit* w);
	MyTime getTime();
	void setTime(MyTime time);

protected:
};


#endif