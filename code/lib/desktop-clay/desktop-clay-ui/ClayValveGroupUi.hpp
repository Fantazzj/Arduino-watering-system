#ifndef CLAY_VALVE_GROUP_UI_HPP
#define CLAY_VALVE_GROUP_UI_HPP

#include "clay.h"
#include <inttypes.h>

struct ValveInfo {
	const char* name = "Etv000";
	uint8_t nameLen = 4;
	bool state = false;
};

struct ValveGroupInfo {
	ValveInfo valves[VALVE_NUM];
	bool mainSwitch = false;
};

class ClayValveGroupUi {
public:
	static constexpr Clay_Color ON_COLOR = {100, 255, 150, 255};
	static constexpr Clay_Color OFF_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color SWITCH_OFF_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color SWITCH_ON_COLOR = {149, 182, 120, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint8_t TEXT_SIZE = 30;

private:
	uint16_t textId;
	int8_t rows;
	int8_t cols;

public:
	explicit ClayValveGroupUi(uint16_t textId);
	void draw(ValveGroupInfo info) const;
	[[nodiscard]] uint16_t getTextId() const;

private:
	void drawValve(ValveInfo info) const;
	void drawValveRow(ValveInfo info[], int8_t n) const;
};

#endif//CLAY_VALVE_GROUP_UI_HPP
