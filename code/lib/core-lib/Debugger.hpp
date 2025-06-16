#ifndef SYSTEM_DEBUGGER_HPP
#define SYSTEM_DEBUGGER_HPP

#include "../date-time-lib/MyDateTime.hpp"

class Debugger {
private:
public:
	virtual ~Debugger() = default;
	virtual void print(const char* text) = 0;
	virtual void print(char c) = 0;
	virtual void print(int n) = 0;
	void print(MyTime time);
	void print(MyDate date);
	void print(MyDateTime dateTime);
	void println(const char* text);
	void println(char c);
	void println(int n);
	void println(MyTime time);
	void println(MyDate date);
	void println(MyDateTime dateTime);
	void println();

protected:
};

#endif//DEBUGGER_HPP
