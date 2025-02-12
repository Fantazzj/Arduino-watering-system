#include "MyTime.hpp"

MyTime::MyTime(uint8_t hour, uint8_t min, uint8_t sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

uintmax_t MyTime::operator+(MyTime a) {
	return this->_toSec() + a._toSec();
}

uintmax_t MyTime::operator-(MyTime a) {
	return this->_toSec() - a._toSec();
}

bool MyTime::operator>(MyTime a) {
	return this->_toSec() > a._toSec();
}

bool MyTime::operator<(MyTime a) {
	return this->_toSec() < a._toSec();
}

bool MyTime::operator==(MyTime a) {
	return this->_toSec() == a._toSec();
}

bool MyTime::operator!=(MyTime a) {
	return this->_toSec() != a._toSec();
}

bool MyTime::operator>=(MyTime a) {
	return this->_toSec() >= a._toSec();
}

bool MyTime::operator<=(MyTime a) {
	return this->_toSec() <= a._toSec();
}

uintmax_t MyTime::_toSec() const {
	return hourToSec(this->hour) + minToSec(this->min) + this->sec;
}
