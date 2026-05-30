#include "ClayValveGroupUi.hpp"

#include <cmath>

ClayValveGroupUi::ClayValveGroupUi(const uint16_t textId) {
	this->textId = textId;
	rows = sqrt(VALVE_NUM);
	cols = VALVE_NUM / rows + (VALVE_NUM % rows > 0);
}

uint16_t ClayValveGroupUi::getTextId() const {
	return textId;
}

void ClayValveGroupUi::draw(ValveGroupInfo info) const {
	CLAY({
			.id = CLAY_ID("ValveGroup"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.padding = {10, 10, 10, 10},
					.childGap = 10,
					.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
			.backgroundColor = info.mainSwitch ? SWITCH_ON_COLOR : SWITCH_OFF_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		for(int8_t i = 0; i < rows; i++) {
			const int8_t from = i * cols;
			const int8_t to = from + (cols - 1) >= VALVE_NUM ? VALVE_NUM - 1 : i * cols + (cols - 1);
			drawValveRow(info.valves + from, to - from);
		}
	}
}

void ClayValveGroupUi::drawValveRow(ValveInfo info[], const int8_t n) const {
	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.childGap = 10,
					.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
	}) {
		for(int8_t i = 0; i <= n; i++)
			drawValve(info[i]);
	}
}

void ClayValveGroupUi::drawValve(const ValveInfo info) const {
	const Clay_TextElementConfig textConfig = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	const Clay_String etvName = {
			.length = static_cast<int32_t>(info.nameLen),
			.chars = info.name,
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
			.backgroundColor = info.state ? ON_COLOR : OFF_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		CLAY_TEXT(etvName, CLAY_TEXT_CONFIG(textConfig));
	}
}
