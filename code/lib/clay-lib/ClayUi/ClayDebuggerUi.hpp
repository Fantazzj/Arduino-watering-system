#ifndef CLAY_DEBUGGER_UI_HPP
#define CLAY_DEBUGGER_UI_HPP

#include <cstdint>
#include <string>

#define DEBUGGER_BG_COLOR {100, 120, 150, 255}
#define DEBUGGER_TEXT_COLOR {50, 50, 50, 255}
#define DEBUGGER_TEXT_SIZE 30

class ClayDebuggerUi {
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
