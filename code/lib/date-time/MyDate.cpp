#include "MyDate.hpp"

MyDate::MyDate(uint8_t dow, uint8_t day, uint8_t mon, uint16_t year) {
	this->dow = dow;
	this->day = day;
	this->mon = mon;
	this->year = year;
}

bool MyDate::operator>(MyDate a) {
	return this->_toDays() > a._toDays();
}

bool MyDate::operator<(MyDate a) {
	return this->_toDays() < a._toDays();
}

bool MyDate::operator==(MyDate a) {
	return this->_toDays() == a._toDays();
}

bool MyDate::operator!=(MyDate a) {
	return this->_toDays() != a._toDays();
}

bool MyDate::operator>=(MyDate a) {
	return this->_toDays() >= a._toDays();
}

bool MyDate::operator<=(MyDate a) {
	return this->_toDays() <= a._toDays();
}

uint64_t MyDate::_toDays() {
	return yearToDay(year) + monToDay(mon) + day;
}
