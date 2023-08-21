#include "MyDate.hpp"

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
