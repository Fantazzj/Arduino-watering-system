#include "ClayValveGroupUi.hpp"

ClayValveGroupUi::ClayValveGroupUi(uint16_t id) {
	textId = id;
	etvStates = {
			false,
			false,
			false,
			false,
			false,
			false,
			false,
			false,
			false,
	};
	mainSwitchState = false;
}

uint16_t ClayValveGroupUi::getEtvsTextId() const {
	return textId;
}

void ClayValveGroupUi::createEtv(int8_t i) {
	Clay_TextElementConfig etvsText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	CLAY(CLAY_RECTANGLE({
				 .color = etvStates[i] ? ON_COLOR : OFF_COLOR,
				 .cornerRadius = {10, 10, 10, 10},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
		 })) {
		Clay_String etvName = {
				.length = static_cast<int32_t>(etvsNames[i].length()),
				.chars = etvsNames[i].c_str(),
		};
		CLAY_TEXT(etvName, CLAY_TEXT_CONFIG(etvsText));
	}
}

void ClayValveGroupUi::createEtvRow(int8_t from, int8_t to) {
	CLAY(CLAY_LAYOUT({
			.sizing = {
					.width = CLAY_SIZING_GROW(),
					.height = CLAY_SIZING_GROW(),
			},
			.childGap = 10,
			.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			.layoutDirection = CLAY_LEFT_TO_RIGHT,
	})) {
		for(int8_t i = from; i <= to; i++)
			createEtv(i);
	}
}

void ClayValveGroupUi::createEtvGroup() {
	CLAY(CLAY_ID("Etvs"),
		 CLAY_RECTANGLE({
				 .color = mainSwitchState ? SWITCH_ON_COLOR : SWITCH_OFF_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .padding = {10, 10, 10, 10},
				 .childGap = 10,
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
		 })) {
		for(int8_t i = 0; i < VALVE_NUM / 3; i++)
			createEtvRow(i * 3, i * 3 + 2);
	}
}

void ClayValveGroupUi::setEtvState(int8_t n, bool state) {
	etvStates[n] = state;
}

void ClayValveGroupUi::setMainSwitchState(bool state) {
	mainSwitchState = state;
}
