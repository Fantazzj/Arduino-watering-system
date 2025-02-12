#include "QtClock.hpp"

QtClock::QtClock() {
	_w = nullptr;
};

void QtClock::begin(ControlUnit* w) {
	this->_w = w;
}

MyDateTime QtClock::getDateTime() {
	MyDateTime time;
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

	time.date.dow = now->tm_wday;
	if(time.date.dow == 0) time.date.dow = Sunday;
	time.time.hour = now->tm_hour;
	time.time.min = now->tm_min;
	time.time.sec = now->tm_sec;
	time.date.day = now->tm_mday;
	time.date.mon = now->tm_mon + 1;
	time.date.year = now->tm_year + 1900;

	return time;
}

void QtClock::setDateTime(MyDateTime time) {
	_w->printOnConsole(QString::number(time.time.hour) + ":" + QString::number((time.time.min)));
	_w->printOnConsole(QString::number(time.date.dow));
	_w->printOnConsole(QString::number(time.date.day) + "/" + QString::number(time.date.mon) + "/" + QString::number(time.date.year));
}
