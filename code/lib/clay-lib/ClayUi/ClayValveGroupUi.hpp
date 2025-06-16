#ifndef CLAY_VALVE_GROUP_UI_HPP
#define CLAY_VALVE_GROUP_UI_HPP

#include "clay.h"
#include <array>
#include <cmath>
#include <cstdint>
#include <string>

class ClayValveGroupUi {
public:
	static constexpr Clay_Color ON_COLOR = {100, 255, 150, 255};
	static constexpr Clay_Color OFF_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color SWITCH_OFF_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color SWITCH_ON_COLOR = {149, 182, 120, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint8_t TEXT_SIZE = 30;
#ifdef WIN64
	static constexpr char FONT[] = "C:/Users/Fantazz/AppData/Local/Microsoft/Windows/Fonts/JetBrainsMono-Regular.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif

private:
	std::array<std::string, VALVE_NUM> etvsNames;
	std::array<bool, VALVE_NUM> etvStates;
	bool mainSwitchState;
	uint16_t textId;
	const int8_t rows = sqrt(VALVE_NUM);
	const int8_t cols = VALVE_NUM / rows;
	void createEtv(int8_t i);
	void createEtvRow(int8_t from, int8_t to);

public:
	explicit ClayValveGroupUi(uint16_t id);
	void createEtvGroup();
	[[nodiscard]] uint16_t getEtvsTextId() const;
	void setEtvState(int8_t n, bool state);
	void setMainSwitchState(bool state);
};

#endif//CLAY_VALVE_GROUP_UI_HPP
