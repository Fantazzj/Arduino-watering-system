#include "QtDebugger.hpp"

QtDebugger::QtDebugger() = default;

void QtDebugger::begin(ControlUnit* w) {
	this->w = w;
}

void QtDebugger::print(const char* text) {
	w->printOnConsole(text);
}

void QtDebugger::print(char c) {
	w->printOnConsole(c);
}

void QtDebugger::print(int n) {
	w->printOnConsole(n);
}
