#include "ClayMoistureUi.hpp"

ClayMoistureUi::ClayMoistureUi() = default;

void ClayMoistureUi::draw(const MoistureInfo& moistureInfo) {
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
			drawLevel(moistureInfo, i);
	}
}

void ClayMoistureUi::drawLevel(const MoistureInfo& moistureInfo, const int8_t n) {
	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIXED(40),
					},
			},
			.backgroundColor = n * LEVEL_NUM <= moistureInfo.moistureLevel ? SELECTED_LEVEL_COLOR : STILL_LEVEL_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		Clay_OnHover(moistureInfo.handler[n], moistureInfo.args);
	}
}
