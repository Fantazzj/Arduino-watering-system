#include "displayUi.h"
#include "clay.h"

const char text[D_HEIGHT][D_LENGTH] = {
		"simple text row1",
		"simple text row2",
};

uint16_t displayTextId;

void setDisplayTextId(uint16_t id) {
	displayTextId = id;
}

uint16_t getDisplayTextId() {
	return displayTextId;
}

void createDisplayChars(int8_t row) {
	Clay_Sizing charSize = {
			.height = CLAY_SIZING_FIXED(50),
			.width = CLAY_SIZING_FIXED(35),
	};

	Clay_Color charBgColor = DISPLAY_BG_COLOR;

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
					 .color = charBgColor,
			 }),
			 CLAY_LAYOUT({
					 .sizing = charSize,
					 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			 })) {
			CLAY_TEXT(displayText, CLAY_TEXT_CONFIG(charText));
		}
	}
}

void createDisplayRows() {
	Clay_Sizing rowSize = {
			.height = CLAY_SIZING_FIT(),
			.width = CLAY_SIZING_FIT(),
	};

	for(int8_t r = 0; r < D_HEIGHT; r++) {
		CLAY(CLAY_LAYOUT({
				.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				.childGap = 5,
				.sizing = rowSize,
		})) {
			createDisplayChars(r);
		}
	}
}

void createDisplay() {
	Clay_Color displayColor = {209, 209, 209, 220};

	CLAY(CLAY_ID("Display"),
		 CLAY_RECTANGLE({
				 .color = displayColor,
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
