#include "MyDateTime.hpp"

MyDateTime::MyDateTime(MyTime time, MyDate date) {
	this->time = time;
	this->date = date;
}

MyDateTime::MyDateTime() {
	this->time = MyTime();
	this->date = MyDate();
}

uint64_t MyDateTime::operator+(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) +
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

uint64_t MyDateTime::operator-(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) -
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

bool MyDateTime::operator>(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) >
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

bool MyDateTime::operator<(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) <
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

bool MyDateTime::operator==(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) ==
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

bool MyDateTime::operator!=(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) !=
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

bool MyDateTime::operator>=(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) >=
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}

bool MyDateTime::operator<=(MyDateTime a) {
	return (this->time._toSec() + dayToSec(this->date._toDays())) <=
		   (a.time._toSec() + dayToSec(a.date._toDays()));
}
