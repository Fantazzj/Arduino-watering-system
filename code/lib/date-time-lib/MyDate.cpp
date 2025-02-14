#include "MyDate.hpp"

MyDate::MyDate(uint8_t dow, uint8_t day, uint8_t mon, uint16_t year) {
	this->dow = dow;
	this->day = day;
	this->mon = mon;
	this->year = year;
}

MyDate::MyDate() {
	this->dow = Monday;
	this->day = 1;
	this->mon = January;
	this->year = 2025;
}

bool MyDate::operator>(const MyDate& a) const {
	return this->_toDays() > a._toDays();
}

bool MyDate::operator<(const MyDate& a) const {
	return this->_toDays() < a._toDays();
}

bool MyDate::operator==(const MyDate& a) const {
	return this->_toDays() == a._toDays();
}

bool MyDate::operator!=(const MyDate& a) const {
	return this->_toDays() != a._toDays();
}

bool MyDate::operator>=(const MyDate& a) const {
	return this->_toDays() >= a._toDays();
}

bool MyDate::operator<=(const MyDate& a) const {
	return this->_toDays() <= a._toDays();
}

uint64_t MyDate::_toDays() const {
	return yearToDay(year) + monToDay(mon) + day;
}
