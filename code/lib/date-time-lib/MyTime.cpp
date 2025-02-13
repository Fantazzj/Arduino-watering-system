#include "MyTime.hpp"

MyTime::MyTime(uint8_t hour, uint8_t min, uint8_t sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

MyTime::MyTime() {
	this->hour = 0;
	this->min = 0;
	this->sec = 0;
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
