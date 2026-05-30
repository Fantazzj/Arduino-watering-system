#ifndef CLAY_DISPLAY_UI_HPP
#define CLAY_DISPLAY_UI_HPP

#include "clay.h"
#include <cinttypes>

struct DisplayInfo {
	char text[DISPLAY_HEIGHT][DISPLAY_LENGTH]{};
	int8_t blinkChar[2]{-1, -1};
	bool backlight{false};
};

class ClayDisplayUi {
public:
	explicit ClayDisplayUi(uint16_t textId);
	void draw(const DisplayInfo& info) const;

	static constexpr uint16_t TEXT_SIZE = 48;

private:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color BASIC_CHAR_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color SELECTED_CHAR_COLOR = {149, 182, 120, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};

	Clay_TextElementConfig textConfig;

	void drawChars(const DisplayInfo& info, int8_t row) const;
	void drawRows(const DisplayInfo& info) const;
};

#endif//CLAY_DISPLAY_UI_HPP
