#ifndef HWCLOCK_CPP
#define HWCLOCK_CPP

#include "../core/Clock.hpp"

class HwClock : public Clock {
private:
	MyDateTime t;
	unsigned long prevMillis = 0;

public:
	HwClock(int8_t rtcRst, int8_t rtcData, int8_t rtcClk);
	MyDateTime getTime() override;
	void setTime(MyDateTime tIn) override;
};

#endif
