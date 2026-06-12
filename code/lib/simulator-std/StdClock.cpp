#include "StdClock.hpp"
#include <chrono>

using namespace std::chrono;

StdClock::StdClock() : dateTime{system_clock::now()} {}

MyDateTime StdClock::getDateTime() {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};
	const year_month_weekday weekday{dateTimeDays};
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	const auto myDateTime = MyDateTime(
			MyTime(time.hours().count(), time.minutes().count(), time.seconds().count()),
			MyDate(weekday.weekday().c_encoding() + 1, static_cast<unsigned>(date.day()), static_cast<unsigned>(date.month()), static_cast<int>(date.year())));

	return myDateTime;
}

void StdClock::setDateTime(const MyDateTime myDateTime) {
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

void StdClock::increaseOneHour() {
	dateTime += hours(1);
}

void StdClock::decreaseOneHour() {
	dateTime -= hours(1);
}

void StdClock::increaseOneMinute() {
	dateTime += minutes(1);
}

void StdClock::decreaseOneMinute() {
	dateTime -= minutes(1);
}

void StdClock::increaseOneDay() {
	dateTime += days(1);
}

void StdClock::decreaseOneDay() {
	dateTime -= days(1);
}

void StdClock::increaseOneMonth() {
	dateTime += months(1);
}

void StdClock::decreaseOneMonth() {
	dateTime -= months(1);
}

void StdClock::increaseOneYear() {
	dateTime += years(1);
}

void StdClock::decreaseOneYear() {
	dateTime -= years(1);
}

std::string StdClock::getDayString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};

	std::string string;
	if(date.day() < 10d) string = '0';
	else string = "";
	string += std::to_string(static_cast<unsigned>(date.day()));

	return string;
}

std::string StdClock::getMonthString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};

	std::string string;
	if(date.month() < std::chrono::October) string = "0";
	else string = "";
	string += std::to_string(static_cast<unsigned>(date.month()));

	return string;
}

std::string StdClock::getYearString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const year_month_day date{dateTimeDays};

	return std::to_string(static_cast<int>(date.year()));
}

std::string StdClock::getHoursString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	std::string string;
	if(time.hours() < 10h) string = "0";
	else string = "";
	string += std::to_string(time.hours().count());

	return string;
}

std::string StdClock::getMinutesString() const {
	const auto dateTimeDays = floor<days>(dateTime);
	const hh_mm_ss time{floor<milliseconds>(dateTime - dateTimeDays)};

	std::string string;
	if(time.minutes() < 10min) string = "0";
	else string = "";
	string += std::to_string(time.minutes().count());

	return string;
}
