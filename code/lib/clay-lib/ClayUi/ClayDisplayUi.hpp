#ifndef CLAY_DISPLAY_UI_HPP
#define CLAY_DISPLAY_UI_HPP

#include "clay.h"
#include <array>
#include <cstdint>
#include <string>

constexpr uint8_t DISPLAY_HEIGHT = 2;
constexpr uint8_t DISPLAY_LENGTH = 16;

constexpr Clay_Color DISPLAY_BG_COLOR = {100, 120, 150, 255};
constexpr Clay_Color DISPLAY_CHAR_COLOR = {101, 157, 213, 255};
constexpr Clay_Color DISPLAY_TEXT_COLOR = {50, 50, 50, 255};
constexpr uint16_t DISPLAY_TEXT_SIZE = 48;

class ClayDisplayUi {
private:
	uint16_t textId;
	std::array<std::string, 2> text;

public:
	explicit ClayDisplayUi(uint16_t id);
	[[nodiscard]] uint16_t getDisplayTextId() const;
	void createDisplay();
	void setDisplayChar(int8_t row, int8_t col, char c);
	void createDisplayChars(int8_t row);
	void createDisplayRows();
};

#endif//CLAY_DISPLAY_UI_HPP
