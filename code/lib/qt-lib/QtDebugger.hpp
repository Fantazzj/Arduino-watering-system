#ifndef QTDEBUGGER_HPP
#define QTDEBUGGER_HPP

#include "../core-lib/Debugger.hpp"
#include "ControlUnit.h"

class QtDebugger : public Debugger {
private:
	ControlUnit* w;

public:
	explicit QtDebugger();
	void begin(ControlUnit* w);
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;

protected:
};

#endif//QTDEBUGGER_HPP
