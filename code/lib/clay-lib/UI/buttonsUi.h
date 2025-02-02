#ifndef BUTTONSUI_H
#define BUTTONSUI_H

#include "stdint.h"

#define BUTTONS_COLOR {255, 0, 0, 255}
#define BUTTONS_BG_COLOR {0, 255, 0, 255}
#define BUTTONS_TEXT_COLOR {255, 255, 255, 255}
#define BUTTONS_TEXT_SIZE 30

void createButtons();

void setButtonsTextId(uint16_t id);
uint16_t getButtonsTextId(void);

#endif//BUTTONSUI_H
