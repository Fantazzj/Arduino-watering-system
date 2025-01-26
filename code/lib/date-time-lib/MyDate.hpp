#ifndef MYDATE_HPP
#define MYDATE_HPP

#if defined(QTDESKTOP)
#	include <cstdint>
#elif defined(HWARDUINO)
#	include <Arduino.h>
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
	explicit MyDate(uint8_t dow = Monday, uint8_t day = 1, uint8_t mon = January, uint16_t year = 2023);

	uint8_t dow;
	uint8_t day;
	uint8_t mon;
	uint16_t year;

	friend class MyDateTime;

	bool operator>(MyDate a);

	bool operator<(MyDate a);

	bool operator==(MyDate a);

	bool operator!=(MyDate a);

	bool operator>=(MyDate a);

	bool operator<=(MyDate a);

private:
	uintmax_t _toDays() const;
};

#endif//MYDATE_HPP
