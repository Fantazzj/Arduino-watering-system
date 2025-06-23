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
#if defined(MINGW) || defined(MSVC)
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif

private:
	uint16_t textId;
	std::string text;

public:
	explicit ClayDebuggerUi(uint16_t textId);
	void createUi();
	[[nodiscard]] uint16_t getTextId() const;
	void appendText(const std::string& text);
};

#endif//CLAY_DEBUGGER_UI_HPP
