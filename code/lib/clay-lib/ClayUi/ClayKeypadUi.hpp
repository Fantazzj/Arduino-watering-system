#ifndef CLAY_KEYPAD_UI_HPP
#define CLAY_KEYPAD_UI_HPP

#include "../ClayKeypad.hpp"
#include "clay.h"
#include <array>
#include <cstdint>
#include <string>

class ClayKeypadUi {
public:
	static constexpr uint8_t NUM = 4;
	static constexpr Clay_Color BUTTONS_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 30;
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";

private:
	uint16_t textId;
	const std::array<std::string, NUM> buttonNames = {
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
