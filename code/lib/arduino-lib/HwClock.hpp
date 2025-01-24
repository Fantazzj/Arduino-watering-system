#ifndef HWCLOCK_CPP
#define HWCLOCK_CPP

#include "../core/Clock.hpp"
#include <TimeLib.h>


class HwClock : public Clock {
private:
public:
	explicit HwClock();
	void begin();
	MyDateTime getTime() override;
	void setTime(MyDateTime tIn) override;
};

#endif
