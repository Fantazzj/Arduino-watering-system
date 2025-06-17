#ifndef CLAYCLOCKUI_HPP
#define CLAYCLOCKUI_HPP

#include "clay.h"
#include <chrono>

#include <cstdint>

class ClayClockUi {
public:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color CHAR_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 48;
#ifdef WIN64
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif
private:
	uint16_t textId;
	std::time_t dateTime;
	std::tm* localDateTime;
	char stringDateDay[3] = "01";
	char stringDateMonth[3] = "01";
	char stringDateYear[5] = "1197";
	char stringTimeHours[3] = "12";
	char stringTimeMinutes[3] = "00";

public:
	explicit ClayClockUi(uint16_t id);
	[[nodiscard]] uint16_t getTextId() const;
	void createClock();

private:
	void createDateEditor();
	void createTimeEditor();
	void createSpacer();
	void createEditor(const char* text, int8_t len);
};


#endif//CLAYCLOCKUI_HPP
