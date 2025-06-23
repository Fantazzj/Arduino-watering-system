#ifndef QTTIMER_HPP
#define QTTIMER_HPP

#include "../core-lib/Timer.hpp"
#include <Arduino.h>

class HwTimer : public Timer {
private:
public:
	explicit HwTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//QTTIMER_HPP
