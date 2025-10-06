#ifndef CLAYTIMER_HPP
#define CLAYTIMER_HPP

#include "../core/Timer.hpp"
#include "ClayControlUnit.hpp"
#include <chrono>

class ClayTimer final : public Timer {
private:
#if defined _MSC_BUILD
	std::chrono::time_point<std::chrono::steady_clock> startTime;
#elif defined __MINGW64__
	std::chrono::time_point<std::chrono::system_clock> startTime;
#else
#error "undefined startTime variable for correct platform"
#endif

public:
	explicit ClayTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//CLAYTIMER_HPP
