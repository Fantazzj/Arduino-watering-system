#ifndef BUTTONSUI_H
#define BUTTONSUI_H

#include "stdint.h"

#define BUTTONS_COLOR {101, 157, 213, 255}
#define BUTTONS_BG_COLOR {100, 120, 150, 255}
#define BUTTONS_TEXT_COLOR {50, 50, 50, 255}
#define BUTTONS_TEXT_SIZE 30

void createButtonGroup();

void setButtonsTextId(uint16_t id);
uint16_t getButtonsTextId(void);

#endif//BUTTONSUI_H
