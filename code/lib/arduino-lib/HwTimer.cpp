#include "HwTimer.hpp"

HwTimer::HwTimer() = default;

void HwTimer::wait(unsigned long t) {
	delay(t);
}

unsigned long HwTimer::millis() {
	return millis();
}
