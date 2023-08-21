#ifndef MYDATETIME_HPP
#define MYDATETIME_HPP

#include "MyDate.hpp"
#include "MyTime.hpp"

#define dayToHour(a) ((a) *24)
#define dayToSec(a) ((a) *86400)
#define hourToDay(a) ((a) / 24)
#define secToDay(a) ((a) / 86400)

struct MyDateTime {
	MyDate date;
	MyTime time;

	uint64_t operator+(MyDateTime a);

	uint64_t operator-(MyDateTime a);

	bool operator>(MyDateTime a);

	bool operator<(MyDateTime a);

	bool operator==(MyDateTime a);

	bool operator!=(MyDateTime a);

	bool operator>=(MyDateTime a);

	bool operator<=(MyDateTime a);
};


#endif//MYDATETIME_HPP
