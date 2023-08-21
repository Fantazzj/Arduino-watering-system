#include "MyTime.hpp"

uint64_t MyTime::operator+(MyTime a) {
	return this->_toSec() + a._toSec();
}

uint64_t MyTime::operator-(MyTime a) {
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

uint64_t MyTime::_toSec() {
	return hourToSec(hour) + minToSec(min) + sec;
}
