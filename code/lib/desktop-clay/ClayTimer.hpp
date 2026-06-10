#ifndef CLAYTIMER_HPP
#define CLAYTIMER_HPP

#include "../core/Timer.hpp"
#include "ClayControlUnit.hpp"
#include <chrono>

class ClayTimer final : public Timer {
	using chronoTime = std::chrono::time_point<std::chrono::system_clock>;

public:
	explicit ClayTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

private:
	chronoTime startTime;

protected:
};

#endif//CLAYTIMER_HPP
