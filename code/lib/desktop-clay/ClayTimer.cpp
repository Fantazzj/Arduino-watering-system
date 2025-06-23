#include "ClayTimer.hpp"

#include <thread>

using namespace std::chrono;
using namespace std::this_thread;

ClayTimer::ClayTimer() {
	startTime = high_resolution_clock::now();
};

void ClayTimer::wait(const unsigned long t) {
	sleep_for(milliseconds(t));
}

unsigned long ClayTimer::millis() {
	const auto currentTime = high_resolution_clock::now();
	return duration_cast<milliseconds>(currentTime - startTime).count();
}
