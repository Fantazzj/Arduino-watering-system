#ifndef CLAYTIMER_HPP
#define CLAYTIMER_HPP

#include "../core-lib/Timer.hpp"
#include "ClayControlUnit.hpp"
#include <chrono>
#include <thread>

class ClayTimer : public Timer {
private:
	std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> startTime;

public:
	explicit ClayTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//CLAYTIMER_HPP
