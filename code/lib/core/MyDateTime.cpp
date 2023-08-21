#include "MyDateTime.hpp"

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
