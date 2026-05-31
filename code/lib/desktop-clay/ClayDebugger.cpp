#include "ClayDebugger.hpp"

ClayDebugger::ClayDebugger() = default;

void ClayDebugger::print(const char* text) {
	this->text.append(text);
}

void ClayDebugger::print(const char c) {
	this->text.append(std::string(1, c));
}

void ClayDebugger::print(const int n) {
	this->text.append(std::to_string(n));
}

std::string_view ClayDebugger::getText() const {
	return text;
}
