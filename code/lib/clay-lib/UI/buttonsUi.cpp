#include "buttonsUi.hpp"

#include <cstdint>
#include <cstdio>

#define BUTTONS_NUM 4

static const Clay_String buttonNames[BUTTONS_NUM] = {
		CLAY_STRING("Cancel"),
		CLAY_STRING("Down"),
		CLAY_STRING("Up"),
		CLAY_STRING("Confirm"),
};

static uint16_t textId;

void ButtonsUi::setButtonsTextId(uint16_t id) {
	textId = id;
}

uint16_t ButtonsUi::getButtonsTextId() {
	return textId;
}

void ButtonsUi::pressHandler(Clay_ElementId elementId, Clay_PointerData pointerData, intptr_t i) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;

	printf("Pressed button n°%lld\n", i);
}

void ButtonsUi::createButton(int8_t i) {
	Clay_TextElementConfig buttonText = {
			.textColor = BUTTONS_TEXT_COLOR,
			.fontId = textId,
			.fontSize = BUTTONS_TEXT_SIZE,
	};

	CLAY(CLAY_RECTANGLE({
				 .color = BUTTONS_COLOR,
				 .cornerRadius = {10, 10, 10, 10},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
		 }),
		 Clay_OnHover(pressHandler, i)) {
		CLAY_TEXT(buttonNames[i], CLAY_TEXT_CONFIG(buttonText));
	}
}

void ButtonsUi::createButtonGroup() {
	CLAY(CLAY_ID("Buttons"),
		 CLAY_RECTANGLE({
				 .color = BUTTONS_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_FIXED(150),
				 },
				 .padding = {10, 10, 10, 10},
				 .childGap = 10,
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .layoutDirection = CLAY_LEFT_TO_RIGHT,
		 })) {
		for(int8_t i = 0; i < BUTTONS_NUM; i++)
			createButton(i);
	}
}
