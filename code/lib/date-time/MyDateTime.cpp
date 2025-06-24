#include "MyDateTime.hpp"

MyDateTime::MyDateTime(const MyTime time, const MyDate date) {
	this->time = time;
	this->date = date;
}

MyDateTime::MyDateTime() {
	this->time = MyTime();
	this->date = MyDate();
}

uint64_t MyDateTime::operator+(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) +
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

uint64_t MyDateTime::operator-(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) -
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

bool MyDateTime::operator>(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) >
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

bool MyDateTime::operator<(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) <
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

bool MyDateTime::operator==(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) ==
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

bool MyDateTime::operator!=(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) !=
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

bool MyDateTime::operator>=(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) >=
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}

bool MyDateTime::operator<=(const MyDateTime& a) const {
	return (this->time.toSecFromMidnight() + dayToSec(this->date.toDaysFromYearZero())) <=
		   (a.time.toSecFromMidnight() + dayToSec(a.date.toDaysFromYearZero()));
}
