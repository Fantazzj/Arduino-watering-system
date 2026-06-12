#ifndef CLAYDEBUGGER_HPP
#define CLAYDEBUGGER_HPP

#include "../core/Debugger.hpp"
#include <string>

class StdDebugger final : public Debugger {
public:
	explicit StdDebugger();
	void print(const char* text) override;
	void print(char c) override;
	void print(int n) override;
	[[nodiscard]] std::string_view getText() const;

private:
	std::string text;
};

#endif//CLAYDEBUGGER_HPP
