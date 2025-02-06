#ifndef CLAY_VALVE_GROUP_UI_HPP
#define CLAY_VALVE_GROUP_UI_HPP

#include <array>
#include <cstdint>
#include <string>

#define ETVS_ON_COLOR {149, 182, 120, 255}
#define ETVS_OFF_COLOR {101, 157, 213, 255}

#define ETVS_BG_COLOR {100, 120, 150, 255}
#define ETVS_TEXT_COLOR {50, 50, 50, 255}
#define ETVS_TEXT_SIZE 30

#define ETV_NUM 9

class ClayValveGroupUi {
private:
	const std::array<std::string, ETV_NUM> etvsNames = {
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
	std::array<bool, ETV_NUM> etvStates;
	uint16_t textId;

public:
	explicit ClayValveGroupUi(uint16_t id);
	void createEtvGroup();
	uint16_t getEtvsTextId() const;
	void setEtvState(int8_t n, bool state);
	void createEtv(int8_t i);
	void createEtvRow(int8_t from, int8_t to);
};

#endif//CLAY_VALVE_GROUP_UI_HPP
