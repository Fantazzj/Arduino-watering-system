#ifndef CLAYCLOCKUI_HPP
#define CLAYCLOCKUI_HPP

#include "clay.h"
#include <chrono>

class ClayClockUi {
public:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color CHAR_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 48;
#if defined(MINGW) || defined(MSVC)
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif
private:
	uint16_t textId;
	std::chrono::local_time<std::chrono::seconds> dateTime;
	std::string stringDateDay;
	std::string stringDateMonth;
	std::string stringDateYear;
	std::string stringTimeHours;
	std::string stringTimeMinutes;

public:
	explicit ClayClockUi(uint16_t id);
	[[nodiscard]] uint16_t getTextId() const;
	void createClock();
	[[nodiscard]] std::chrono::local_time<std::chrono::seconds> getDateTime() const;
	void setDateTime(std::chrono::local_time<std::chrono::seconds> dateTime);

private:
	typedef void(*ClayHandler_t)(Clay_ElementId, Clay_PointerData, intptr_t args);
	void createDateEditor();
	void createTimeEditor();
	void createSpacer();
	void createEditor(const std::string& num, ClayHandler_t pressHandlerAdd, ClayHandler_t pressHandlerSub);
	void updateStrings();
	static void genericHandler(std::chrono::local_time<std::chrono::seconds>* dateTime, std::chrono::duration<intmax_t> delta, bool increase);
	static void increaseOneHour(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneHour(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneMinute(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneMinute(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneDay(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneDay(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneMonth(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneMonth(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneYear(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneYear(Clay_ElementId, Clay_PointerData, intptr_t args);
};

#endif//CLAYCLOCKUI_HPP
