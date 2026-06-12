#include "StdTimer.hpp"

#include <thread>

using namespace std::chrono;
using namespace std::this_thread;

StdTimer::StdTimer() {
	startTime = high_resolution_clock::now();
};

void StdTimer::wait(const unsigned long t) {
	sleep_for(milliseconds(t));
}

unsigned long StdTimer::millis() {
	const auto currentTime = high_resolution_clock::now();
	return duration_cast<milliseconds>(currentTime - startTime).count();
}
