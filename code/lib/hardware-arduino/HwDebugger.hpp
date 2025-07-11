#ifndef HWDEBUGGER_HPP
#define HWDEBUGGER_HPP

#include "../core/Debugger.hpp"
#include <Arduino.h>

class HwDebugger : public Debugger {
private:
public:
	explicit HwDebugger();
	void begin(unsigned long baud);
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;

protected:
};

#endif//HWDEBUGGER_HPP
