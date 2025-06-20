#include "ClayDisplayUi.hpp"

ClayDisplayUi::ClayDisplayUi(const uint16_t id) {
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

void ClayDisplayUi::createDisplayChars(const int8_t row) {
	const Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	for(int8_t c = 0; c < DISPLAY_LENGTH; c++) {
		const Clay_String displayText = {
				.length = 1,
				.chars = &text[row][c],
		};

		CLAY({
				.layout{
						.sizing = {
								.width = CLAY_SIZING_FIT(40),
								.height = CLAY_SIZING_FIT(70),
						},
						.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				},
				.backgroundColor = blinkChar[0] == row && blinkChar[1] == c ? SELECTED_CHAR_COLOR : BASIC_CHAR_COLOR,
				.cornerRadius = {10, 10, 10, 10},
		}) {
			CLAY_TEXT(displayText, CLAY_TEXT_CONFIG(charText));
		}
	}
}

void ClayDisplayUi::createDisplayRows() {
	for(int8_t r = 0; r < DISPLAY_HEIGHT; r++) {
		CLAY({
				.layout = {
						.sizing = {
								.width = CLAY_SIZING_FIT(),
								.height = CLAY_SIZING_FIT(),
						},
						.childGap = 5,
						.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				},
		}) {
			createDisplayChars(r);
		}
	}
}

void ClayDisplayUi::createDisplay() {
	CLAY({
			.id = CLAY_ID("Display"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {5, 5, 5, 5},
					.childGap = 5,
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		createDisplayRows();
	}
}

void ClayDisplayUi::setDisplayChar(const int8_t row, const int8_t col, const char c) {
	text[row][col] = c;
}

void ClayDisplayUi::setBlinkOn(const int8_t row, const int8_t col) {
	blinkChar[0] = row;
	blinkChar[1] = col;
}
