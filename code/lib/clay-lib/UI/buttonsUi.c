#include "buttonsUi.h"

#include "clay.h"
#include <stdint.h>
#include <stdio.h>

#define BUTTONS_NUM 4

static const Clay_String buttonNames[BUTTONS_NUM] = {
		CLAY_STRING("Cancel"),
		CLAY_STRING("Down"),
		CLAY_STRING("Up"),
		CLAY_STRING("Confirm"),
};

static uint16_t textId;

void setButtonsTextId(uint16_t id) {
	textId = id;
}

uint16_t getButtonsTextId() {
	return textId;
}

static void pressHandler(Clay_ElementId elementId, Clay_PointerData pointerData, intptr_t i) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;

	printf("Pressed button n°%lld\n", i);
}

static void createButton(int8_t i) {
	Clay_TextElementConfig buttonText = {
			.fontId = textId,
			.fontSize = BUTTONS_TEXT_SIZE,
			.textColor = BUTTONS_TEXT_COLOR,
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

void createButtonGroup() {
	CLAY(CLAY_ID("Buttons"),
		 CLAY_RECTANGLE({
				 .color = BUTTONS_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_LEFT_TO_RIGHT,
				 .padding = {10, 10, 10, 10},
				 .childGap = 10,
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_FIXED(150),
				 },
		 })) {
		for(int8_t i = 0; i < BUTTONS_NUM; i++)
			createButton(i);
	}
}
