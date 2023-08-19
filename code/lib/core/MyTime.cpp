#include "MyTime.hpp"

bool MyTime::isDifferent(MyTime t1, MyTime t2) {
	if(t1.dow != t2.dow) return true;
	else if(t1.min != t2.min) return true;
	else if(t1.hour != t2.hour) return true;
	//else if(t1.sec != t2.sec) return true;
	else if(t1.date != t2.date) return true;
	else if(t1.mon != t2.mon) return true;
	else if(t1.year != t2.year) return true;
	else return false;
}

bool MyTime::isEqual(MyTime t1, MyTime t2) {
	return !isDifferent(t1, t2);
}

bool MyTime::timeIsNextOrEq(MyTime t1, MyTime t2) {
	if(t1.hour > t2.hour) return true;
	else if(t1.hour == t2.hour) {
		if(t1.min > t2.min) return true;
		else if(t1.min == t2.min) {
			if(t1.sec >= t2.sec) return true;
			else return false;
		} else return false;
	} else return false;
}

uint16_t MyTime::elapsedHours(MyTime t1, MyTime t2) {//Only for <=24h
	uint16_t hours;

	hours = t2.hour - t1.hour;
	if(hours < 0) hours += 24;

	return hours;
}

uint16_t MyTime::elapsedMin(MyTime t1, MyTime t2) {
	uint16_t hoursMin;
	uint16_t minutes;

	hoursMin = elapsedHours(t1, t2) * 60;

	minutes = t2.min - t1.min;
	if(minutes < 0) minutes += 60;

	return minutes + hoursMin;
}

uint16_t MyTime::elapsedSec(MyTime t1, MyTime t2) {
	uint16_t minutesSec;
	uint16_t seconds;

	minutesSec = elapsedMin(t1, t2) * 60;

	seconds = t2.sec - t1.sec;
	if(seconds < 0) seconds += 60;

	return seconds + minutesSec;
}

void MyTime::freeze(unsigned long ms) {
#ifdef HWARDUINO
	delay(ms);
#endif
#ifdef QTDESKTOP

#endif
}
