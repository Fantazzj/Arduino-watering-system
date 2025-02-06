#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <cstdint>

#define D_HEIGHT 2
#define D_LENGTH 16

#define DISPLAY_BG_COLOR {100, 120, 150, 255}
#define DISPLAY_CHAR_COLOR {101, 157, 213, 255}
#define DISPLAY_TEXT_COLOR {50, 50, 50, 255}
#define DISPLAY_TEXT_SIZE 48

class DisplayUi {
public:
	static void setDisplayTextId(uint16_t id);
	static uint16_t getDisplayTextId();
	static void createDisplay();
	static void setDisplayChar(int8_t row, int8_t col, char c);
	static void createDisplayChars(int8_t row);
	static void createDisplayRows();
};

#endif//DISPLAYUI_H
