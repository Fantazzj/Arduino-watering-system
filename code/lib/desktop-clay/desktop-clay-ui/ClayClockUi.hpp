#ifndef CLAYCLOCKUI_HPP
#define CLAYCLOCKUI_HPP

#include "clay.h"

typedef void (*ClayHandler_t)(Clay_ElementId, Clay_PointerData, intptr_t args);

struct ClockInfo {
	char DateDay[3]{"01"};
	char DateMonth[3]{"01"};
	char DateYear[5]{"2000"};
	char TimeHours[3]{"00"};
	char TimeMinutes[3]{"00"};
	ClayHandler_t increaseOneDay{};
	ClayHandler_t decreaseOneDay{};
	ClayHandler_t increaseOneMonth{};
	ClayHandler_t decreaseOneMonth{};
	ClayHandler_t increaseOneYear{};
	ClayHandler_t decreaseOneYear{};
	ClayHandler_t increaseOneHour{};
	ClayHandler_t decreaseOneHour{};
	ClayHandler_t increaseOneMinute{};
	ClayHandler_t decreaseOneMinute{};
	intptr_t args{};
};

class ClayClockUi {
public:
	explicit ClayClockUi(uint16_t textId);
	void draw(const ClockInfo& info) const;

	static constexpr uint16_t TEXT_SIZE = 48;

private:
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color CHAR_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};

	Clay_TextElementConfig textConfig;

	void drawDateEditor(const ClockInfo& info) const;
	void drawTimeEditor(const ClockInfo& info) const;
	void drawSpacer() const;
	void drawEditor(const ClockInfo& info, const char* num, int8_t len, ClayHandler_t pressHandlerAdd, ClayHandler_t pressHandlerSub) const;
};

#endif//CLAYCLOCKUI_HPP
