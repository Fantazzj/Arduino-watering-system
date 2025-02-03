#include "buttonsUi.h"

#include "clay.h"
#include <stdint.h>

#define BUTTONS_NUM 4

const Clay_String buttonNames[BUTTONS_NUM] = {
		{
				.chars = "Cancel",
				.length = 6,
		},
		{
				.chars = "Down",
				.length = 4,
		},
		{
				.chars = "Up",
				.length = 2,
		},
		{
				.chars = "Confirm",
				.length = 7,
		},
};

uint16_t buttonsTextId;

void setButtonsTextId(uint16_t id) {
	buttonsTextId = id;
}

uint16_t getButtonsTextId() {
	return buttonsTextId;
}

void createButton(int8_t i) {
	Clay_TextElementConfig buttonText = {
			.fontId = buttonsTextId,
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
						 .height = CLAY_SIZING_FIT(BUTTONS_TEXT_SIZE + 5, BUTTONS_TEXT_SIZE + 25),
				 },
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
		 })) {
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
						 .height = CLAY_SIZING_FIT(0,0),
				 },
		 })) {
		for(int8_t i = 0; i < BUTTONS_NUM; i++)
			createButton(i);
	}
}
