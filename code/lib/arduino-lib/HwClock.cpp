#include "HwClock.hpp"

HwClock::HwClock() {
	char z = '0';

	t.date.day = __DATE__[5] - z + (__DATE__[4] - z) * 10;
	t.date.mon = September;
	t.date.year = __DATE__[10] - z + (__DATE__[9] - z) * 10 + (__DATE__[8] - z) * 100 + (__DATE__[7] - z) * 1000;
	t.date.dow = Monday;

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
