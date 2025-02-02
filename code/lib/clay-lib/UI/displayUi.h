#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <stdint.h>

#define D_HEIGHT 2
#define D_LENGTH 16

#define CHAR_BG_COLOR {255, 0, 0, 255}
#define CHAR_TEXT_COLOR {255, 255, 255, 255}
#define CHAR_TEXT_SIZE 48

void setCharTextId(uint16_t id);
uint16_t getCharTextId(void);

void createDisplay(void);

#endif//DISPLAYUI_H
