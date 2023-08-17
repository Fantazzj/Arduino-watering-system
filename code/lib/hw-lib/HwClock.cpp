#include "HwClock.hpp"

HwClock::HwClock(int8_t rtcRst, int8_t rtcData, int8_t rtcClk) {
	t.date = 14;
	t.mon = 8;
	t.year = 2023;

	char z = '0';
	t.hour = __TIME__[1] - z + (__TIME__[0] - z) * 10;
	t.min = __TIME__[4] - z + (__TIME__[3] - z) * 10;
	t.sec = __TIME__[7] - z + (__TIME__[6] - z) * 10;

	t.dow = Sunday;
}

MyTime HwClock::getTime() {
	unsigned long elapMillis = millis();

	t.sec += (elapMillis - prevMillis) / 1000ul;
	t.min += t.sec / 60;
	t.hour += t.min / 60;
	t.date += t.hour / 24;

	t.sec %= 60;
	t.min %= 60;
	t.hour %= 24;

	if(elapMillis - prevMillis >= 1000ul)
		prevMillis = elapMillis;

	return t;
}

void HwClock::setTime(MyTime tIn) {
	t.date = tIn.date;
	t.mon = tIn.mon;
	t.year = tIn.year;
	t.hour = tIn.hour;
	t.min = tIn.min;
	t.sec = tIn.sec;
	t.dow = tIn.dow;
}
