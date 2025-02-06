#ifndef CLAY_VALVE_GROUP_UI_HPP
#define CLAY_VALVE_GROUP_UI_HPP

#include "clay.h"
#include <array>
#include <cstdint>
#include <string>

constexpr Clay_Color VALVE_ON_COLOR = {149, 182, 120, 255};
constexpr Clay_Color VALVE_OFF_COLOR = {101, 157, 213, 255};

constexpr Clay_Color VALVE_BG_COLOR = {100, 120, 150, 255};
constexpr Clay_Color VALVE_TEXT_COLOR = {50, 50, 50, 255};
constexpr uint8_t VALVE_TEXT_SIZE = 30;

class ClayValveGroupUi {
private:
	const std::array<std::string, VALVE_NUM> etvsNames = {
			"Etv1",
			"Etv2",
			"Etv3",
			"Etv4",
			"Etv5",
			"Etv6",
			"Etv7",
			"Etv8",
			"Etv9",
	};
	std::array<bool, VALVE_NUM> etvStates;
	uint16_t textId;

public:
	explicit ClayValveGroupUi(uint16_t id);
	void createEtvGroup();
	[[nodiscard]] uint16_t getEtvsTextId() const;
	void setEtvState(int8_t n, bool state);
	void createEtv(int8_t i);
	void createEtvRow(int8_t from, int8_t to);
};

#endif//CLAY_VALVE_GROUP_UI_HPP
