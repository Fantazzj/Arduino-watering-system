#include "ClayValveGroupUi.hpp"

#include <cmath>

ClayValveGroupUi::ClayValveGroupUi(const uint16_t id) {
	textId = id;
	for(int8_t i = 0; i < VALVE_NUM; i++) {
		etvsNames[i] = std::string("Etv") + std::to_string(i + 1);
		etvStates[i] = false;
	}
	mainSwitchState = false;
	rows = sqrt(VALVE_NUM);
	cols = VALVE_NUM / rows + (VALVE_NUM % rows > 0);
}

uint16_t ClayValveGroupUi::getEtvsTextId() const {
	return textId;
}

void ClayValveGroupUi::createEtvGroup() {
	CLAY({
			.id = CLAY_ID("Etvs"),
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
			.backgroundColor = mainSwitchState ? SWITCH_ON_COLOR : SWITCH_OFF_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		for(int8_t i = 0; i < rows; i++) {
			const int8_t from = i * cols;
			const int8_t to = from + (cols - 1) >= VALVE_NUM ? VALVE_NUM - 1 : i * cols + (cols - 1);
			createEtvRow(from, to);
		}
	}
}

void ClayValveGroupUi::createEtvRow(const int8_t from, const int8_t to) {
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
		for(int8_t i = from; i <= to; i++)
			createEtv(i);
	}
}

void ClayValveGroupUi::createEtv(const int8_t i) {
	const Clay_TextElementConfig etvsText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
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
			.backgroundColor = etvStates[i] ? ON_COLOR : OFF_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		const Clay_String etvName = {
				.length = static_cast<int32_t>(etvsNames[i].length()),
				.chars = etvsNames[i].c_str(),
		};
		CLAY_TEXT(etvName, CLAY_TEXT_CONFIG(etvsText));
	}
}

void ClayValveGroupUi::setEtvState(const uint8_t n, const bool state) {
	etvStates[n] = state;
}

void ClayValveGroupUi::setMainSwitchState(const bool state) {
	mainSwitchState = state;
}
