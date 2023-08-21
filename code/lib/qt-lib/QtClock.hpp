#ifndef QT_CLOCK_CPP
#define QT_CLOCK_CPP

#include "../core/Clock.hpp"
#include "ControlUnit.h"
#include <QString>

class QtClock : public Clock {
private:
	ControlUnit* _w;

public:
	QtClock(ControlUnit* w);
	MyDateTime getTime();
	void setTime(MyDateTime time);

protected:
};


#endif