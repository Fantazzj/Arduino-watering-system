#pragma once

#include "../core/Timer.hpp"
#include "../ui-clay/ClayControlUnit.hpp"
#include <chrono>

class StdTimer final : public Timer {
	using chronoTime = std::chrono::time_point<std::chrono::system_clock>;

public:
	explicit StdTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

private:
	chronoTime startTime;
};
