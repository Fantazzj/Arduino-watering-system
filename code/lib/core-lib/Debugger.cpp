#include "Debugger.hpp"

void Debugger::print(MyTime time) {
	print((int) time.hour);
	print(':');
	print((int) time.min);
	print(':');
	print((int) time.sec);
}

void Debugger::print(MyDate date) {
	print((int) date.day);
	print(':');
	print((int) date.mon);
	print(':');
	print((int) date.year);
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
