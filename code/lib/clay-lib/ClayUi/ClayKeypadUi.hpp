#ifndef CLAY_KEYPAD_UI_HPP
#define CLAY_KEYPAD_UI_HPP

#include "../ClayKeypad.hpp"
#include "clay.h"
#include <array>
#include <cstdint>
#include <string>

constexpr uint8_t BUTTONS_NUM = 4;

constexpr Clay_Color BUTTONS_COLOR = {101, 157, 213, 255};
constexpr Clay_Color BUTTONS_BG_COLOR = {100, 120, 150, 255};
constexpr Clay_Color BUTTONS_TEXT_COLOR = {50, 50, 50, 255};
constexpr uint16_t BUTTONS_TEXT_SIZE = 30;

class ClayKeypadUi {
private:
	uint16_t textId;
	const std::array<std::string, BUTTONS_NUM> buttonNames = {
			"Cancel",
			"Down",
			"Up",
			"Confirm",
	};

public:
	explicit ClayKeypadUi(uint16_t id);
	void createButtonGroup();
	[[nodiscard]] uint16_t getButtonsTextId() const;
	void createButton(int8_t i);
	void setKeypad(ClayKeypad* keypad);
};

#endif//CLAY_KEYPAD_UI_HPP
