#include "HwClock.hpp"

HwClock::HwClock() = default;

void HwClock::begin() {
	char z = '0';

	uint8_t day = __DATE__[5] - z + (((__DATE__[4] - z) * 10) >= 0 ? (__DATE__[4] - z) * 10 : 0);
	uint8_t mon = 6;
	uint8_t year = __DATE__[10] - z + (__DATE__[9] - z) * 10 + (__DATE__[8] - z) * 100 + (__DATE__[7] - z) * 1000;

	uint8_t hour = __TIME__[1] - z + (__TIME__[0] - z) * 10;
	uint8_t min = __TIME__[4] - z + (__TIME__[3] - z) * 10;
	uint8_t sec = __TIME__[7] - z + (__TIME__[6] - z) * 10;

	::setTime(hour, min, sec, day, mon, year);
}

MyDateTime HwClock::getDateTime() {
	MyDateTime out;

	out.time.hour = hour();
	out.time.min = minute();
	out.time.sec = second();

	out.date.year = year();
	out.date.mon = month();
	out.date.day = day();
	out.date.dow = weekday();

	return out;
}

void HwClock::setDateTime(MyDateTime t) {
	::setTime(t.time.hour, t.time.min, t.time.sec,
			  t.date.day, t.date.mon, t.date.year);
}
