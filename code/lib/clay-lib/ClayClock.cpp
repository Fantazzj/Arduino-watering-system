#include "ClayClock.hpp"
#include <chrono>

using std::chrono::system_clock;

ClayClock::ClayClock() {
	w = nullptr;
}

void ClayClock::begin(ClayControlUnit* w) {
	this->w = w;
}

MyDateTime ClayClock::getDateTime() {
	const auto now = system_clock::now();
	const auto now_time = system_clock::to_time_t(now);
	const auto time = localtime(&now_time);

	return MyDateTime(
			MyTime(time->tm_hour, time->tm_min, time->tm_sec),
			MyDate(time->tm_wday + 1, time->tm_mday, time->tm_mon, time->tm_year + 1900));
}

void ClayClock::setDateTime(const MyDateTime time) {
}
