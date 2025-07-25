#ifndef MYDATE_HPP
#define MYDATE_HPP

#if defined __has_include
#	if __has_include(<cstdlib>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
#endif

#define dayToMon(a) ((uint64_t(a)) / 30)
#define dayToYear(a) ((uint64_t(a)) / 365)
#define monToDay(a) ((uint64_t(a)) * 30)
#define monToYear(a) ((uint64_t(a)) / 12)
#define yearToDay(a) ((uint64_t(a)) * 365)
#define yearToMon(a) ((uint64_t(a)) * 12)

enum Dow : uint8_t {
	Sunday = 1,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

enum Month : uint8_t {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

struct MyDate {
	MyDate(uint8_t dow, uint8_t, uint8_t mon, uint16_t year);
	MyDate();
	uint8_t dow;
	uint8_t day;
	uint8_t mon;
	uint16_t year;
	bool operator>(const MyDate& a) const;
	bool operator<(const MyDate& a) const;
	bool operator==(const MyDate& a) const;
	bool operator!=(const MyDate& a) const;
	bool operator>=(const MyDate& a) const;
	bool operator<=(const MyDate& a) const;
	uintmax_t toDaysFromYearZero() const;
};

#endif//MYDATE_HPP
