#include "ClayClock.hpp"
#include <chrono>

using std::chrono::system_clock;
using namespace std::chrono;

ClayClock::ClayClock() {
	w = nullptr;
}

void ClayClock::begin(ClayControlUnit* w) {
	this->w = w;
}

MyDateTime ClayClock::getDateTime() {
	const auto timeClock = w->getDateTime();

	const auto dateTimeDays = floor<days>(timeClock);
	const year_month_day date{dateTimeDays};
	const year_month_weekday weekday{dateTimeDays};
	const hh_mm_ss time{floor<milliseconds>(timeClock - dateTimeDays)};

	const auto dateTime = MyDateTime(
			MyTime(time.hours().count(), time.minutes().count(), time.seconds().count()),
			MyDate(weekday.weekday().c_encoding(), static_cast<unsigned>(date.day()), static_cast<unsigned>(date.month()), static_cast<int>(date.year())));

	return dateTime;
}

void ClayClock::setDateTime(const MyDateTime time) {
	const year_month_day date_spec{
			year{time.date.year},
			month{time.date.mon},
			day{time.date.day}};

	const hh_mm_ss time_spec{
			hours{time.time.hour} +
			minutes{time.time.min} +
			seconds{time.time.sec}};

	const time_point<system_clock> dateTime = sys_days{date_spec} + time_spec.to_duration();

	w->setDateTime(dateTime);
}
