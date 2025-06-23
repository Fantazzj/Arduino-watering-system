#ifndef CLAYDEBUGGER_HPP
#define CLAYDEBUGGER_HPP

#include "../core/Debugger.hpp"
#include "ClayControlUnit.hpp"

class ClayDebugger final : public Debugger {
private:
	ClayControlUnit* w;

public:
	explicit ClayDebugger();
	void begin(ClayControlUnit* w);
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;

protected:
};


#endif//CLAYDEBUGGER_HPP
