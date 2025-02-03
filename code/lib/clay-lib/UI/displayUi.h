#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <stdint.h>

#define D_HEIGHT 2
#define D_LENGTH 16

#define DISPLAY_BG_COLOR {100, 120, 150, 255}
#define DISPLAY_CHAR_COLOR {101, 157, 213, 255}
#define DISPLAY_TEXT_COLOR {50, 50, 50, 255}
#define DISPLAY_TEXT_SIZE 48

void setDisplayTextId(uint16_t id);
uint16_t getDisplayTextId(void);

void createDisplay(void);

#endif//DISPLAYUI_H
