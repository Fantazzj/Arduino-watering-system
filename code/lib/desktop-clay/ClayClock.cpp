#include "ClayClock.hpp"
#include <chrono>

using namespace std::chrono;

ClayClock::ClayClock() : dateTime{system_clock::now()} {}

MyDateTime ClayClock::getDateTime() {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};
	const year_month_weekday weekday{dateTimeDays};
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	const auto myDateTime = MyDateTime(
			MyTime(time.hours().count(), time.minutes().count(), time.seconds().count()),
			MyDate(weekday.weekday().c_encoding() + 1, static_cast<unsigned>(date.day()), static_cast<unsigned>(date.month()), static_cast<int>(date.year())));

	return myDateTime;
}

void ClayClock::setDateTime(const MyDateTime myDateTime) {
	const year_month_day date_spec{
			year{myDateTime.date.year},
			month{myDateTime.date.mon},
			day{myDateTime.date.day}};

	const hh_mm_ss time_spec{
			hours{myDateTime.time.hour} +
			minutes{myDateTime.time.min} +
			seconds{myDateTime.time.sec}};

	dateTime = sys_days{date_spec} + time_spec.to_duration();
}

void ClayClock::increaseOneHour() {
	dateTime += hours(1);
}

void ClayClock::decreaseOneHour() {
	dateTime -= hours(1);
}

void ClayClock::increaseOneMinute() {
	dateTime += minutes(1);
}

void ClayClock::decreaseOneMinute() {
	dateTime -= minutes(1);
}

void ClayClock::increaseOneDay() {
	dateTime += days(1);
}

void ClayClock::decreaseOneDay() {
	dateTime -= days(1);
}

void ClayClock::increaseOneMonth() {
	dateTime += months(1);
}

void ClayClock::decreaseOneMonth() {
	dateTime -= months(1);
}

void ClayClock::increaseOneYear() {
	dateTime += years(1);
}

void ClayClock::decreaseOneYear() {
	dateTime -= years(1);
}

std::string ClayClock::getDayString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};

	std::string string;
	if(date.day() < 10d) string = '0';
	else string = "";
	string += std::to_string(static_cast<unsigned>(date.day()));

	return string;
}

std::string ClayClock::getMonthString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};

	std::string string;
	if(date.month() < std::chrono::October) string = "0";
	else string = "";
	string += std::to_string(static_cast<unsigned>(date.month()));

	return string;
}

std::string ClayClock::getYearString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};

	return std::to_string(static_cast<int>(date.year()));
}

std::string ClayClock::getHoursString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	std::string string;
	if(time.hours() < 10h) string = "0";
	else string = "";
	string += std::to_string(time.hours().count());

	return string;
}

std::string ClayClock::getMinutesString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	std::string string;
	if(time.minutes() < 10min) string = "0";
	else string = "";
	string += std::to_string(time.minutes().count());

	return string;
}
