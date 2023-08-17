#ifndef MY_TIME_CPP//TODO improve
#define MY_TIME_CPP

#ifdef QTDESKTOP
#include <cstdint>
#endif

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

class MyTime {
public:
	uint8_t hour = 0;
	uint8_t min = 0;
	uint8_t sec = 0;
	uint8_t date = 1;
	uint8_t mon = January;
	uint16_t year = 2023;
	uint8_t dow = Monday;

	static bool isDifferent(MyTime t1, MyTime t2);
	static bool isEqual(MyTime t1, MyTime t2);
	static bool timeIsNextOrEq(MyTime t1, MyTime t2);
	static uint16_t elapsedHours(MyTime t1, MyTime t2);
	static uint16_t elapsedMin(MyTime t1, MyTime t2);
	static uint16_t elapsedSec(MyTime t1, MyTime t2);
	static void freeze(unsigned long ms);
};

#endif//MY_TIME_CPP
