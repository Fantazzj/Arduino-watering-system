#include "ClayDisplayUi.hpp"

ClayDisplayUi::ClayDisplayUi(const uint16_t textId) {
	this->textId = textId;
	text = {
			"                ",
			"                ",
	};
	blinkChar[0] = -1;
	blinkChar[1] = -1;
	backlight = false;
}

uint16_t ClayDisplayUi::getTextId() const {
	return textId;
}

void ClayDisplayUi::createChars(const int8_t row) {
	const Clay_TextElementConfig charTextConfig = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	for(int8_t c = 0; c < DISPLAY_LENGTH; c++) {
		const Clay_String charText = {
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
			if(backlight) { CLAY_TEXT(charText, CLAY_TEXT_CONFIG(charTextConfig)); }
		}
	}
}

void ClayDisplayUi::createRows() {
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
			createChars(r);
		}
	}
}

void ClayDisplayUi::createUi() {
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
		createRows();
	}
}

void ClayDisplayUi::setChar(const int8_t row, const int8_t col, const char c) {
	text[row][col] = c;
}

void ClayDisplayUi::setBlinkOn(const int8_t row, const int8_t col) {
	blinkChar[0] = row;
	blinkChar[1] = col;
}

void ClayDisplayUi::setBacklight(const bool state) {
	backlight = state;
}

bool ClayDisplayUi::getBacklight() const {
	return backlight;
}
