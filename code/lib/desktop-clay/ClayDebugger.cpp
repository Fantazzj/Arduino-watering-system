#include "ClayDebugger.hpp"

ClayDebugger::ClayDebugger() {
	w = nullptr;
};

void ClayDebugger::begin(ClayControlUnit* w) {
	this->w = w;
}

void ClayDebugger::print(const char* text) {
	w->debuggerLog(text);
}

void ClayDebugger::print(const char c) {
	w->debuggerLog(std::string(1, c));
}

void ClayDebugger::print(const int n) {
	w->debuggerLog(std::to_string(n));
}
