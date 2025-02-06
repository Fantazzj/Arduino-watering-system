#include "displayUi.hpp"
#include "clay.h"

static char text[D_HEIGHT][D_LENGTH + 1] = {
		"SAMPLE TEXT ROW1",
		"SAMPLE TEXT ROW2",
};

static uint16_t textId;

void DisplayUi::setDisplayTextId(uint16_t id) {
	textId = id;
}

uint16_t DisplayUi::getDisplayTextId() {
	return textId;
}

void DisplayUi::createDisplayChars(int8_t row) {
	Clay_TextElementConfig charText = {
			.textColor = DISPLAY_TEXT_COLOR,
			.fontId = textId,
			.fontSize = DISPLAY_TEXT_SIZE,
	};

	for(int8_t c = 0; c < D_LENGTH; c++) {
		Clay_String displayText = {
				.length = 1,
				.chars = text[row] + c,
		};

		CLAY(CLAY_RECTANGLE({
					 .color = DISPLAY_CHAR_COLOR,
					 .cornerRadius = {10, 10, 10, 10},
			 }),
			 CLAY_LAYOUT({
					 .sizing = {
							 .width = CLAY_SIZING_FIT(50),
							 .height = CLAY_SIZING_FIT(70),
					 },
					 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			 })) {
			CLAY_TEXT(displayText, CLAY_TEXT_CONFIG(charText));
		}
	}
}

void DisplayUi::createDisplayRows() {
	for(int8_t r = 0; r < D_HEIGHT; r++) {
		CLAY(CLAY_LAYOUT({
				.sizing = {
						.width = CLAY_SIZING_FIT(),
						.height = CLAY_SIZING_FIT(),
				},
				.childGap = 5,
				.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
		})) {
			createDisplayChars(r);
		}
	}
}

void DisplayUi::createDisplay() {
	CLAY(CLAY_ID("Display"),
		 CLAY_RECTANGLE({
				 .color = DISPLAY_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_FIT(),
						 .height = CLAY_SIZING_FIT(),
				 },
				 .padding = {5, 5, 5, 5},
				 .childGap = 5,
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
		 })) {
		createDisplayRows();
	}
}

void DisplayUi::setDisplayChar(int8_t row, int8_t col, char c) {
	text[row][col] = c;
}
