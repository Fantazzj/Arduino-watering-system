#include "QtClock.hpp"

QtClock::QtClock(ControlUnit* w) {
	this->_w = w;
}

MyTime QtClock::getTime() {
	MyTime time;
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	time.dow = now->tm_wday;
	if(time.dow == 0) time.dow = Sunday;
	time.hour = now->tm_hour;
	time.min = now->tm_min;
	time.sec = now->tm_sec;
	time.date = now->tm_mday;
	time.mon = now->tm_mon + 1;
	time.year = now->tm_year + 1900;

	return time;
}

void QtClock::setTime(MyTime time) {
	_w->printOnConsole(QString::number(time.hour) + ":" + QString::number((time.min)));
	_w->printOnConsole(QString::number(time.dow));
	_w->printOnConsole(QString::number(time.date) + "/" + QString::number(time.mon) + "/" + QString::number(time.sec));
}
