#ifndef MYTIME_LIBRARY_H
#define MYTIME_LIBRARY_H

#if defined __has_include
#	if __has_include(<cstdlib>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
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

	uintmax_t operator+(const MyTime& a) const;

	uintmax_t operator-(const MyTime& a) const;

	bool operator>(const MyTime& a) const;

	bool operator<(const MyTime& a) const;

	bool operator==(const MyTime& a) const;

	bool operator!=(const MyTime& a) const;

	bool operator>=(const MyTime& a) const;

	bool operator<=(const MyTime& a) const;

private:
	[[nodiscard]] uintmax_t _toSec() const;
};

#endif//MYTIME_LIBRARY_H
