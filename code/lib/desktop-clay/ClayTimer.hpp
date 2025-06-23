#ifndef CLAYTIMER_HPP
#define CLAYTIMER_HPP

#include "../core/Timer.hpp"
#include "ClayControlUnit.hpp"
#include <chrono>

class ClayTimer final : public Timer {
private:
#ifdef MSVC
	std::chrono::time_point<std::chrono::steady_clock> startTime;
#else
	std::chrono::time_point<std::chrono::system_clock> startTime;
#endif

public:
	explicit ClayTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//CLAYTIMER_HPP
