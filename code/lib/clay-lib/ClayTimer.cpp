#include "ClayTimer.hpp"

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

ClayTimer::ClayTimer() {
	startTime = high_resolution_clock::now();
};

void ClayTimer::wait(unsigned long t) {
	std::this_thread::sleep_for(milliseconds(t));
}

unsigned long ClayTimer::millis() {
	auto currentTime = high_resolution_clock::now();
	return duration_cast<milliseconds>(currentTime - startTime).count();
}
