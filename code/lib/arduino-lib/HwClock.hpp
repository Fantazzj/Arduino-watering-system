#ifndef HWCLOCK_CPP
#define HWCLOCK_CPP

#include "TimeLib.h"
#include "../core/Clock.hpp"

class HwClock : public Clock {
private:
public:
	HwClock();
	MyDateTime getTime() override;
	void setTime(MyDateTime tIn) override;
};

#endif
