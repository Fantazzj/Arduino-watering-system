#ifndef BUTTONSUI_H
#define BUTTONSUI_H

#include "clay.h"
#include <cstdint>

#define BUTTONS_COLOR {101, 157, 213, 255}
#define BUTTONS_BG_COLOR {100, 120, 150, 255}
#define BUTTONS_TEXT_COLOR {50, 50, 50, 255}
#define BUTTONS_TEXT_SIZE 30

class ButtonsUi {
public:
	static void createButtonGroup();
	static void setButtonsTextId(uint16_t id);
	static uint16_t getButtonsTextId();
	static void pressHandler(Clay_ElementId elementId, Clay_PointerData pointerData, intptr_t i);
	static void createButton(int8_t i);
};

#endif//BUTTONSUI_H
