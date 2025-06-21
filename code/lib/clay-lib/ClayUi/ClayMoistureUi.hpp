#ifndef CLAY_MOISTURE_UI_HPP
#define CLAY_MOISTURE_UI_HPP

#include "clay.h"

class ClayMoistureUi {
public:
	static constexpr uint8_t LEVEL_NUM = 10;
	static constexpr Clay_Color STILL_LEVEL_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color SELECTED_LEVEL_COLOR = {149, 182, 120, 255};
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};

private:
	struct HandlerArgsType {
		int8_t num;
		uint8_t* moistureLevel;
	};
	uint8_t moistureLevel;
	HandlerArgsType myArgs[LEVEL_NUM];
	static void updateMoistureHandler(Clay_ElementId, Clay_PointerData pointerData, intptr_t myArgs);

public:
	ClayMoistureUi();
	void createUi();
	void createLevel(int8_t n);
	[[nodiscard]] uint8_t getMoistureLevel() const;
};

#endif//CLAY_MOISTURE_UI_HPP
