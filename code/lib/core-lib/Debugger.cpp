#include "Debugger.hpp"

void Debugger::print(MyTime time) {
	print(time.hour);
	print(':');
	print(time.min);
	print(':');
	print(time.sec);
}

void Debugger::print(MyDate date) {
	print(date.day);
	print(':');
	print(date.mon);
	print(':');
	print(date.year);
}

void Debugger::print(MyDateTime dateTime) {
	print(dateTime.date);
	print(' ');
	print(dateTime.time);
}

void Debugger::println(const char* text) {
	print(text);
	println();
}

void Debugger::println(char c) {
	print(c);
	println();
}

void Debugger::println(int n) {
	print(n);
	println();
}

void Debugger::println(MyTime time) {
	print(time);
	println();
}

void Debugger::println(MyDate date) {
	print(date);
	println();
}

void Debugger::println(MyDateTime dateTime) {
	print(dateTime);
	println();
}

void Debugger::println() {
	print('\n');
}
