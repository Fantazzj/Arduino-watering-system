#ifndef HWCLOCK_CPP
#define HWCLOCK_CPP

#include "../core-lib/Clock.hpp"
#include <TimeLib.h>


class HwClock : public Clock {
private:
public:
	explicit HwClock();
	void begin();
	MyDateTime getDateTime() override;
	void setDateTime(MyDateTime tIn) override;
};

#endif
