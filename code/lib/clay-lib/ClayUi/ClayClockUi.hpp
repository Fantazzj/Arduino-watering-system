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
	std::tm* localDateTime;
	std::string stringDateDay;
	std::string stringDateMonth;
	std::string stringDateYear;
	std::string stringTimeHours;
	std::string stringTimeMinutes;

public:
	explicit ClayClockUi(uint16_t id);
	[[nodiscard]] uint16_t getTextId() const;
	void createClock();
	[[nodiscard]] std::tm* getDateTime() const;
	void setDateTime(std::tm* localDateTime);

private:
	void createDateEditor();
	void createTimeEditor();
	void createSpacer();
	void createEditor(const std::string& num);
	static void pressHandler(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
};

#endif//CLAYCLOCKUI_HPP
