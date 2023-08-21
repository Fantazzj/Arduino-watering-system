#ifndef MYTIME_LIBRARY_H
#define MYTIME_LIBRARY_H

#ifdef QTDESKTOP
#	include <cstdint>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#define secToMin(a) ((a) / 60)
#define secToHour(a) ((a) / 3600)
#define minToSec(a) ((a) *60)
#define minToHour(a) ((a) / 60)
#define hourToMin(a) ((a) *60)
#define hourToSec(a) ((a) *3600)

struct MyTime {
	uint8_t hour = 0;
	uint8_t min = 0;
	uint8_t sec = 0;

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