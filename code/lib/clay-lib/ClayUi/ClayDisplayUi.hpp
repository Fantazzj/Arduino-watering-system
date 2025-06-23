#ifndef CLAY_DISPLAY_UI_HPP
#define CLAY_DISPLAY_UI_HPP

#include "clay.h"
#include <array>
#include <cstdint>
#include <string>

class ClayDisplayUi {
public:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color BASIC_CHAR_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color SELECTED_CHAR_COLOR = {149, 182, 120, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 48;
#if defined(MINGW) || defined(MSVC)
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif

private:
	uint16_t textId;
	std::array<std::string, DISPLAY_HEIGHT> text;
	int16_t blinkChar[2];
	bool backlight;

public:
	explicit ClayDisplayUi(uint16_t textId);
	[[nodiscard]] uint16_t getTextId() const;
	void createUi();
	void setChar(int8_t row, int8_t col, char c);
	void setBlinkOn(int8_t row, int8_t col);
	void setBacklight(bool state);
	[[nodiscard]] bool getBacklight() const;

private:
	void createChars(int8_t row);
	void createRows();
};

#endif//CLAY_DISPLAY_UI_HPP
