#pragma once

#include "../core/Clock.hpp"
#include <chrono>
#include <string>

class StdClock final : public Clock {
	using chronoTime = std::chrono::time_point<std::chrono::system_clock>;
	using chornoDuration = std::chrono::duration<intmax_t>;

public:
	explicit StdClock();
	MyDateTime getDateTime() override;
	void setDateTime(MyDateTime myDateTime) override;
	void increaseOneHour();
	void decreaseOneHour();
	void increaseOneMinute();
	void decreaseOneMinute();
	void increaseOneDay();
	void decreaseOneDay();
	void increaseOneMonth();
	void decreaseOneMonth();
	void increaseOneYear();
	void decreaseOneYear();
	[[nodiscard]] std::string getDayString() const;
	[[nodiscard]] std::string getMonthString() const;
	[[nodiscard]] std::string getYearString() const;
	[[nodiscard]] std::string getHoursString() const;
	[[nodiscard]] std::string getMinutesString() const;

private:
	chronoTime dateTime;
};
