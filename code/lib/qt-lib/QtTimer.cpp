#include "QtTimer.hpp"

QtTimer::QtTimer() = default;

void QtTimer::wait(unsigned long t) {
	QThread::msleep(t);
}

unsigned long QtTimer::millis() {
	return 0;
}
