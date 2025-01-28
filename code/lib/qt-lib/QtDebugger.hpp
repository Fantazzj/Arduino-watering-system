#ifndef QTDEBUGGER_HPP
#define QTDEBUGGER_HPP

#include "../core-lib/Debugger.hpp"
#include <QDebug>

class QtDebugger : public Debugger {
private:
public:
	explicit QtDebugger();
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;

protected:
};

#endif//QTDEBUGGER_HPP
