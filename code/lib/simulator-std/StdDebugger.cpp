#include "StdDebugger.hpp"

StdDebugger::StdDebugger() = default;

void StdDebugger::print(const char* text) {
	this->text.append(text);
}

void StdDebugger::print(const char c) {
	this->text.append(std::string(1, c));
}

void StdDebugger::print(const int n) {
	this->text.append(std::to_string(n));
}

std::string_view StdDebugger::getText() const {
	return text;
}
