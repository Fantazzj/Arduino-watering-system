#ifndef HWDEBUGGER_HPP
#define HWDEBUGGER_HPP

#include "../core-lib/Debugger.hpp"
#include <Arduino.h>

class HwDebugger : public Debugger {
private:
public:
	explicit HwDebugger();
	void begin(int baud);
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;

protected:
};

#endif//HWDEBUGGER_HPP
