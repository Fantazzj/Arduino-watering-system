#include "ClayDisplayUi.hpp"

ClayDisplayUi::ClayDisplayUi(uint16_t id) {
	textId = id;
	text = {
			"Sample text row1",
			"Sample text row2",
	};
	blinkChar[0] = -1;
	blinkChar[1] = -1;
}

uint16_t ClayDisplayUi::getDisplayTextId() const {
	return textId;
}

void ClayDisplayUi::createDisplayChars(int8_t row) {
	Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	for(int8_t c = 0; c < COLUMNS; c++) {
		Clay_String displayText = {
				.length = 1,
				.chars = &text[row][c],
		};

		CLAY(CLAY_RECTANGLE({
					 .color = blinkChar[0] == row && blinkChar[1] == c ? SELECTED_CHAR_COLOR : BASIC_CHAR_COLOR,
					 .cornerRadius = {10, 10, 10, 10},
			 }),
			 CLAY_LAYOUT({
					 .sizing = {
							 .width = CLAY_SIZING_FIT(40),
							 .height = CLAY_SIZING_FIT(70),
					 },
					 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			 })) {
			CLAY_TEXT(displayText, CLAY_TEXT_CONFIG(charText));
		}
	}
}

void ClayDisplayUi::createDisplayRows() {
	for(int8_t r = 0; r < ROWS; r++) {
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

void ClayDisplayUi::createDisplay() {
	CLAY(CLAY_ID("Display"),
		 CLAY_RECTANGLE({
				 .color = BG_COLOR,
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

void ClayDisplayUi::setDisplayChar(int8_t row, int8_t col, char c) {
	text[row][col] = c;
}

void ClayDisplayUi::setBlinkOn(int8_t row, int8_t col) {
	blinkChar[0] = row;
	blinkChar[1] = col;
}
