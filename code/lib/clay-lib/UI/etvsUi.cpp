#include "etvsUi.hpp"

#include "clay.h"

EtvsUi::EtvsUi(uint16_t id) {
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
}

uint16_t EtvsUi::getEtvsTextId() const {
	return textId;
}

static const Clay_Color etvsOnColor = ETVS_ON_COLOR;
static const Clay_Color etvsOffColor = ETVS_OFF_COLOR;

void EtvsUi::createEtv(int8_t i) {
	Clay_TextElementConfig etvsText = {
			.textColor = ETVS_TEXT_COLOR,
			.fontId = textId,
			.fontSize = ETVS_TEXT_SIZE,
	};

	CLAY(CLAY_RECTANGLE({
				 .color = etvStates[i] ? etvsOnColor : etvsOffColor,
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

void EtvsUi::createEtvRow(int8_t from, int8_t to) {
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

void EtvsUi::createEtvGroup() {
	CLAY(CLAY_ID("Etvs"),
		 CLAY_RECTANGLE({
				 .color = ETVS_BG_COLOR,
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
		for(int8_t i = 0; i < ETV_NUM / 3; i++)
			createEtvRow(i * 3, i * 3 + 2);
	}
}

void EtvsUi::setEtvState(int8_t n, bool state) {
	etvStates[n] = state;
}

void EtvsUi::activateEtv(int8_t n) {
	setEtvState(n, true);
}

void EtvsUi::deactivateEtv(int8_t n) {
	setEtvState(n, false);
}
