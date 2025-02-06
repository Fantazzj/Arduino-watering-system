#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <array>
#include <cstdint>
#include <string>

#define D_HEIGHT 2
#define D_LENGTH 16

#define DISPLAY_BG_COLOR {100, 120, 150, 255}
#define DISPLAY_CHAR_COLOR {101, 157, 213, 255}
#define DISPLAY_TEXT_COLOR {50, 50, 50, 255}
#define DISPLAY_TEXT_SIZE 48

class DisplayUi {
private:
	uint16_t textId;
	std::array<std::string, 2> text;

public:
	explicit DisplayUi(uint16_t id);
	[[nodiscard]] uint16_t getDisplayTextId() const;
	void createDisplay();
	void setDisplayChar(int8_t row, int8_t col, char c);
	void createDisplayChars(int8_t row);
	void createDisplayRows();
};

#endif//DISPLAYUI_H
