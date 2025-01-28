#ifndef QT_CLOCK_CPP
#define QT_CLOCK_CPP

#include "../core-lib/Clock.hpp"
#include "ControlUnit.h"
#include <QString>

class QtClock : public Clock {
private:
	ControlUnit* _w;

public:
	explicit QtClock();
	void begin(ControlUnit* w);
	MyDateTime getDateTime() override;
	void setDateTime(MyDateTime time) override;

protected:
};

#endif
