#include "ClayMoistureUi.hpp"

ClayMoistureUi::ClayMoistureUi() {
	moistureLevel = 0;

	for(int8_t i = 0; i < LEVEL_NUM; i++) {
		myArgs[i].num = i;
		myArgs[i].self = this;
	}
}

void ClayMoistureUi::createMoistureGroup() {
	CLAY({
			.id = CLAY_ID("Moisture"),
			.layout{
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {10, 10, 10, 10},
					.childGap = 10,
					.childAlignment = {
							CLAY_ALIGN_X_CENTER,
							CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		for(int8_t i = 0; i < LEVEL_NUM; i++)
			createLevel(i);
	}
}

void ClayMoistureUi::createLevel(const int8_t i) {
	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIXED(40),
					},
			},
			.backgroundColor = i * LEVEL_NUM <= moistureLevel ? SELECTED_LEVEL_COLOR : STILL_LEVEL_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		Clay_OnHover(ClayMoistureUi::pressHandler, reinterpret_cast<intptr_t>(&myArgs[i]));
	}
}

void ClayMoistureUi::pressHandler(Clay_ElementId, const Clay_PointerData pointerData, intptr_t myArgs) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;

	const auto* args = reinterpret_cast<PressHandlerArgs*>(myArgs);

	args->self->moistureLevel = args->num * 10;
}

uint8_t ClayMoistureUi::getMoisture() const {
	return moistureLevel;
}
