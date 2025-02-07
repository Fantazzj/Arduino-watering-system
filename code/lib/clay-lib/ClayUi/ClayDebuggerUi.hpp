#ifndef CLAY_DEBUGGER_UI_HPP
#define CLAY_DEBUGGER_UI_HPP

#include "clay.h"
#include <cstdint>
#include <string>

class ClayDebuggerUi {
public:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 30;

private:
	uint16_t textId;
	std::string text;

public:
	explicit ClayDebuggerUi(uint16_t id);
	void createDebugger();
	[[nodiscard]] uint16_t getDebuggerTextId() const;
	void appendDebuggerText(std::string string);
};

#endif//CLAY_DEBUGGER_UI_HPP
