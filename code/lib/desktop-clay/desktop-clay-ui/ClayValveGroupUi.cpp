#include "ClayValveGroupUi.hpp"

#include <cmath>

ClayValveGroupUi::ClayValveGroupUi(const uint16_t textId) {
	this->textId = textId;
	for(int8_t i = 0; i < VALVE_NUM; i++) {
		etvNames[i] = std::string("Etv") + std::to_string(i + 1);
		etvStates[i] = false;
	}
	mainSwitchState = false;
	rows = sqrt(VALVE_NUM);
	cols = VALVE_NUM / rows + (VALVE_NUM % rows > 0);
}

uint16_t ClayValveGroupUi::getTextId() const {
	return textId;
}

void ClayValveGroupUi::createUi() {
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

void ClayValveGroupUi::createEtv(const int8_t n) {
	const Clay_TextElementConfig textConfig = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	const Clay_String etvName = {
			.length = static_cast<int32_t>(etvNames[n].length()),
			.chars = etvNames[n].c_str(),
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
			.backgroundColor = etvStates[n] ? ON_COLOR : OFF_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		CLAY_TEXT(etvName, CLAY_TEXT_CONFIG(textConfig));
	}
}

void ClayValveGroupUi::setValveState(const uint8_t n, const bool state) {
	etvStates[n] = state;
}

void ClayValveGroupUi::setMainSwitchState(const bool state) {
	mainSwitchState = state;
}
