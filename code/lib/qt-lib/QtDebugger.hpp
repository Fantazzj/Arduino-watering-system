#ifndef QTDEBUGGER_HPP
#define QTDEBUGGER_HPP

#include "../core-lib/Debugger.hpp"
#include "QtControlUnit.hpp"

class QtDebugger : public Debugger {
private:
	QtControlUnit* w;

public:
	explicit QtDebugger();
	void begin(QtControlUnit* w);
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;

protected:
};

#endif//QTDEBUGGER_HPP
