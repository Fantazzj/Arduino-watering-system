#include "MyDate.hpp"

MyDate::MyDate(const uint8_t dow, const uint8_t day, const uint8_t mon, const uint16_t year) {
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
	return this->toDaysFromYearZero() > a.toDaysFromYearZero();
}

bool MyDate::operator<(const MyDate& a) const {
	return this->toDaysFromYearZero() < a.toDaysFromYearZero();
}

bool MyDate::operator==(const MyDate& a) const {
	return this->toDaysFromYearZero() == a.toDaysFromYearZero();
}

bool MyDate::operator!=(const MyDate& a) const {
	return this->toDaysFromYearZero() != a.toDaysFromYearZero();
}

bool MyDate::operator>=(const MyDate& a) const {
	return this->toDaysFromYearZero() >= a.toDaysFromYearZero();
}

bool MyDate::operator<=(const MyDate& a) const {
	return this->toDaysFromYearZero() <= a.toDaysFromYearZero();
}

uint64_t MyDate::toDaysFromYearZero() const {
	return yearToDay(year) + monToDay(mon) + day;
}
