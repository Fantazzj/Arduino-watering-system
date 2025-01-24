#ifndef QT_CLOCK_CPP
#define QT_CLOCK_CPP

#include "../core/Clock.hpp"
#include "ControlUnit.h"
#include <QString>

class QtClock : public Clock {
private:
	ControlUnit* _w;

public:
	explicit QtClock();
	void begin(ControlUnit* w);
	MyDateTime getTime() override;
	void setTime(MyDateTime time) override;

protected:
};


#endif