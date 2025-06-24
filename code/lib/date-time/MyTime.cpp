#include "MyTime.hpp"

MyTime::MyTime(const uint8_t hour, const uint8_t min, const uint8_t sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

MyTime::MyTime() {
	this->hour = 0;
	this->min = 0;
	this->sec = 0;
}

uintmax_t MyTime::operator+(const MyTime& a) const {
	return this->toSecFromMidnight() + a.toSecFromMidnight();
}

uintmax_t MyTime::operator-(const MyTime& a) const {
	return this->toSecFromMidnight() - a.toSecFromMidnight();
}

bool MyTime::operator>(const MyTime& a) const {
	return this->toSecFromMidnight() > a.toSecFromMidnight();
}

bool MyTime::operator<(const MyTime& a) const {
	return this->toSecFromMidnight() < a.toSecFromMidnight();
}

bool MyTime::operator==(const MyTime& a) const {
	return this->toSecFromMidnight() == a.toSecFromMidnight();
}

bool MyTime::operator!=(const MyTime& a) const {
	return this->toSecFromMidnight() != a.toSecFromMidnight();
}

bool MyTime::operator>=(const MyTime& a) const {
	return this->toSecFromMidnight() >= a.toSecFromMidnight();
}

bool MyTime::operator<=(const MyTime& a) const {
	return this->toSecFromMidnight() <= a.toSecFromMidnight();
}

uintmax_t MyTime::toSecFromMidnight() const {
	return hourToSec(this->hour) + minToSec(this->min) + this->sec;
}
