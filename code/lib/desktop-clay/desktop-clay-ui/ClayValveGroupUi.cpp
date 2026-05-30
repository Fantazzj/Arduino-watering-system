#include "ClayValveGroupUi.hpp"

#include <cmath>

ClayValveGroupUi::ClayValveGroupUi(const uint16_t textId) :
	textConfig{.textColor = TEXT_COLOR, .fontId = textId, .fontSize = TEXT_SIZE},
	rows(static_cast<int8_t>(sqrt(VALVE_NUM))),
	cols(VALVE_NUM / rows + (VALVE_NUM % rows > 0)),
	clayValveNames() {
	for(int8_t i = 0; i < VALVE_NUM; i++) {
		valveNames[i] = "Etv" + std::to_string(i + 1);
		clayValveNames[i].chars = valveNames[i].c_str();
		clayValveNames[i].length = static_cast<int32_t>(valveNames[i].length());
	}
}

void ClayValveGroupUi::draw(const ValveGroupInfo& info) const {
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
			drawValveRow(clayValveNames + from, info.states + from, to - from);
		}
	}
}

void ClayValveGroupUi::drawValveRow(const Clay_String* names, const bool* states, const int8_t n) const {
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
			drawValve(names[i], states[i]);
	}
}

void ClayValveGroupUi::drawValve(const Clay_String name, const bool state) const {
	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
			.backgroundColor = state ? ON_COLOR : OFF_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		CLAY_TEXT(name, CLAY_TEXT_CONFIG(textConfig));
	}
}
