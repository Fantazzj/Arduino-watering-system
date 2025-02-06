#ifndef BUTTONSUI_H
#define BUTTONSUI_H

#include "../ClayKeypad.hpp"
#include <array>
#include <cstdint>
#include <string>

#define BUTTONS_COLOR {101, 157, 213, 255}
#define BUTTONS_BG_COLOR {100, 120, 150, 255}
#define BUTTONS_TEXT_COLOR {50, 50, 50, 255}
#define BUTTONS_TEXT_SIZE 30

#define BUTTONS_NUM 4

class ButtonsUi {
private:
	uint16_t textId;
	const std::array<std::string, BUTTONS_NUM> buttonNames = {
			"Cancel",
			"Down",
			"Up",
			"Confirm",
	};

public:
	explicit ButtonsUi(uint16_t id);
	void createButtonGroup();
	[[nodiscard]] uint16_t getButtonsTextId() const;
	void createButton(int8_t i);
	void setKeypad(ClayKeypad* keypad);
};

#endif//BUTTONSUI_H
