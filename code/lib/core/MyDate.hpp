#ifndef MYDATE_HPP
#define MYDATE_HPP

#ifdef QTDESKTOP
#	include <cstdint>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#define dayToMon(a) ((a) / 30)
#define dayToYear(a) ((a) / 365)
#define monToDay(a) ((a) *30)
#define monToYear(a) ((a) / 12)
#define yearToDay(a) ((a) *365)
#define yearToMon(a) ((a) *12)

enum Dow : uint8_t {
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
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
	uint8_t dow = Monday;
	uint8_t day = 1;
	uint8_t mon = January;
	uint16_t year = 2023;

	friend class MyDateTime;

	bool operator>(MyDate a);

	bool operator<(MyDate a);

	bool operator==(MyDate a);

	bool operator!=(MyDate a);

	bool operator>=(MyDate a);

	bool operator<=(MyDate a);

private:
	uint64_t _toDays();
};

#endif//MYDATE_HPP
