#ifndef CLAYTIMER_HPP
#define CLAYTIMER_HPP

#include "../core-lib/Timer.hpp"
#include "ClayControlUnit.hpp"
#include <chrono>
#include <thread>

class ClayTimer final : public Timer {
private:
	std::chrono::time_point<std::chrono::system_clock> startTime;

public:
	explicit ClayTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//CLAYTIMER_HPP
