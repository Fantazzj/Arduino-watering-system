#ifndef MYTIME_LIBRARY_H
#define MYTIME_LIBRARY_H

#if defined(QTDESKTOP)
#	include <cstdint>
#elif defined(HWARDUINO)
#	include <Arduino.h>
#endif

#define secToMin(a) ((uint64_t(a)) / 60)
#define secToHour(a) ((uint64_t(a)) / 3600)
#define minToSec(a) ((uint64_t(a)) * 60)
#define minToHour(a) ((uint64_t(a)) / 60)
#define hourToMin(a) ((uint64_t(a)) * 60)
#define hourToSec(a) ((uint64_t(a)) * 3600)

struct MyTime {
	explicit MyTime(uint8_t hour, uint8_t min, uint8_t sec);
	MyTime();

	uint8_t hour;
	uint8_t min;
	uint8_t sec;

	friend class MyDateTime;

	uintmax_t operator+(MyTime a);

	uintmax_t operator-(MyTime a);

	bool operator>(MyTime a);

	bool operator<(MyTime a);

	bool operator==(MyTime a);

	bool operator!=(MyTime a);

	bool operator>=(MyTime a);

	bool operator<=(MyTime a);

private:
	uintmax_t _toSec() const;
};

#endif//MYTIME_LIBRARY_H
