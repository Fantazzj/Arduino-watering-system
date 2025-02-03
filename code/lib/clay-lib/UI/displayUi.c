#include "displayUi.h"
#include "clay.h"

const char text[D_HEIGHT][D_LENGTH] = {
		"SAMPLE TEXT ROW1",
		"SAMPLE TEXT ROW2",
};

uint16_t displayTextId;

void setDisplayTextId(uint16_t id) {
	displayTextId = id;
}

uint16_t getDisplayTextId() {
	return displayTextId;
}

void createDisplayChars(int8_t row) {
	Clay_TextElementConfig charText = {
			.fontId = displayTextId,
			.fontSize = DISPLAY_TEXT_SIZE,
			.textColor = DISPLAY_TEXT_COLOR,
	};

	for(int8_t c = 0; c < D_LENGTH; c++) {
		Clay_String displayText = {
				.chars = text[row] + c,
				.length = 1,
		};

		CLAY(CLAY_RECTANGLE({
					 .color = DISPLAY_CHAR_COLOR,
					 .cornerRadius = {10, 10, 10, 10},
			 }),
			 CLAY_LAYOUT({
					 .sizing = {
							 .height = CLAY_SIZING_FIT(70),
							 .width = CLAY_SIZING_FIT(50),
					 },
					 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			 })) {
			CLAY_TEXT(displayText, CLAY_TEXT_CONFIG(charText));
		}
	}
}

void createDisplayRows() {
	for(int8_t r = 0; r < D_HEIGHT; r++) {
		CLAY(CLAY_LAYOUT({
				.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				.childGap = 5,
				.sizing = {
						.height = CLAY_SIZING_FIT(),
						.width = CLAY_SIZING_FIT(),
				},
		})) {
			createDisplayChars(r);
		}
	}
}

void createDisplay() {
	CLAY(CLAY_ID("Display"),
		 CLAY_RECTANGLE({
				 .color = DISPLAY_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .sizing = {
						 .height = CLAY_SIZING_FIT(),
						 .width = CLAY_SIZING_FIT(),
				 },
				 .childGap = 5,
				 .padding = {5, 5, 5, 5},
		 })) {
		createDisplayRows();
	}
}
