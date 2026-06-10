#ifndef CLAY_MOISTURE_UI_HPP
#define CLAY_MOISTURE_UI_HPP

#include "clay.h"

typedef void (*ClayHandler_t)(Clay_ElementId, Clay_PointerData, intptr_t args);

struct MoistureInfo {
	uint8_t moistureLevel{0};
	ClayHandler_t handler[10]{};
	intptr_t args{};
};

class ClayMoistureUi {
public:
	ClayMoistureUi();
	void draw(const MoistureInfo& moistureInfo);
	void drawLevel(const MoistureInfo& moistureInfo, int8_t n);

private:
	static constexpr uint8_t LEVEL_NUM = 10;
	static constexpr Clay_Color STILL_LEVEL_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color SELECTED_LEVEL_COLOR = {149, 182, 120, 255};
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
};

#endif//CLAY_MOISTURE_UI_HPP
