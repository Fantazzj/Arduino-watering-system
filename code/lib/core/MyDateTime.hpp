#ifndef MYDATETIME_HPP
#define MYDATETIME_HPP

#include "MyDate.hpp"
#include "MyTime.hpp"

#define dayToHour(a) ((uint64_t(a)) *24)
#define dayToSec(a) ((uint64_t(a)) *86400)
#define hourToDay(a) ((uint64_t(a)) / 24)
#define secToDay(a) ((uint64_t(a)) / 86400)

class MyDateTime {
public:
	explicit MyDateTime(MyTime time = MyTime(), MyDate date = MyDate());
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
