#ifndef MYTIME_LIBRARY_H
#define MYTIME_LIBRARY_H

#ifdef QTDESKTOP
#	include <cstdint>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#define secToMin(a) ((uint64_t(a)) / 60)
#define secToHour(a) ((uint64_t(a)) / 3600)
#define minToSec(a) ((uint64_t(a)) *60)
#define minToHour(a) ((uint64_t(a)) / 60)
#define hourToMin(a) ((uint64_t(a)) *60)
#define hourToSec(a) ((uint64_t(a)) *3600)

struct MyTime {
	MyTime(uint8_t hour = 0, uint8_t min = 0, uint8_t sec = 0);

	uint8_t hour;
	uint8_t min;
	uint8_t sec;

	friend class MyDateTime;

	uint64_t operator+(MyTime a);

	uint64_t operator-(MyTime a);

	bool operator>(MyTime a);

	bool operator<(MyTime a);

	bool operator==(MyTime a);

	bool operator!=(MyTime a);

	bool operator>=(MyTime a);

	bool operator<=(MyTime a);

private:
	uint64_t _toSec();
};

#endif//MYTIME_LIBRARY_H
