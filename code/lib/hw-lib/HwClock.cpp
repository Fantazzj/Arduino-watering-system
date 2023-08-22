#include "HwClock.hpp"

HwClock::HwClock(int8_t rtcRst, int8_t rtcData, int8_t rtcClk) {
	t.date.dow = Monday;
	t.date.day = 14;
	t.date.mon = September;
	t.date.year = 2023;

	char z = '0';
	t.time.hour = __TIME__[1] - z + (__TIME__[0] - z) * 10;
	t.time.min = __TIME__[4] - z + (__TIME__[3] - z) * 10;
	t.time.sec = __TIME__[7] - z + (__TIME__[6] - z) * 10;
}

MyDateTime HwClock::getTime() {
	unsigned long elapMillis = millis();

	t.time.sec += (elapMillis - prevMillis) / 1000ul;
	t.time.min += t.time.sec / 60;
	t.time.hour += t.time.min / 60;
	t.date.day += t.time.hour / 24;

	t.time.sec %= 60;
	t.time.min %= 60;
	t.time.hour %= 24;

	if(elapMillis - prevMillis >= 1000ul)
		prevMillis = elapMillis;

	return t;
}

void HwClock::setTime(MyDateTime tIn) {
	t = tIn;
}
