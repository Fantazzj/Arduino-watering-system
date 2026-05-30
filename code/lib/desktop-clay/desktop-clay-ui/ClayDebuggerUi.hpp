#ifndef CLAY_DEBUGGER_UI_HPP
#define CLAY_DEBUGGER_UI_HPP

#include "clay.h"
#include <cinttypes>
#include <string>

class ClayDebuggerUi {
public:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 30;

private:
	Clay_TextElementConfig textConfig;
	std::string text;

public:
	explicit ClayDebuggerUi(uint16_t textId);
	void draw() const;
	void appendText(const std::string& text);
};

#endif//CLAY_DEBUGGER_UI_HPP
