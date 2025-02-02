#include "buttonsUi.h"

#include "clay.h"
#include <stdint.h>

#define B_NUM 4

const char buttonNames[B_NUM][8] = {
		"Cancel",
		"Down",
		"Up",
		"Confirm",
};

void createButton(int8_t i) {
	Clay_String buttonName = {
			.chars = buttonNames[i],
			.length = 2,
	};

	Clay_TextElementConfig buttonText = {
			.fontId = 0,
			.fontSize = 48,
			.textColor = {255, 255, 255, 255},
	};

	CLAY(CLAY_RECTANGLE({.color = {255, 0, 0, 255}}),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_FIT(),
				 },
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
		 })) {
		CLAY_TEXT(buttonName, CLAY_TEXT_CONFIG(buttonText));
	}
}

void createButtons() {
	CLAY(CLAY_ID("Buttons"),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_LEFT_TO_RIGHT,
				 .padding = {5, 5, 5, 5},
				 .childGap = 5,
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_FIT(),
				 },
		 })) {
		for(int8_t i = 0; i < B_NUM; i++)
			createButton(i);
	}
}
