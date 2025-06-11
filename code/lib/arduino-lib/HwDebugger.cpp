#include "HwDebugger.hpp"

HwDebugger::HwDebugger() = default;

void HwDebugger::begin(unsigned long baud) {
	Serial.begin(baud);
}

void HwDebugger::print(const char* text) {
	Serial.print(text);
}

void HwDebugger::print(char c) {
	Serial.print(c);
}

void HwDebugger::print(int n) {
	Serial.print(n);
}
