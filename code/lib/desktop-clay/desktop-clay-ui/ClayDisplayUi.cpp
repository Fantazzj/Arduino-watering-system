#include "ClayDisplayUi.hpp"

ClayDisplayUi::ClayDisplayUi(const uint16_t textId) :
	textConfig{.textColor = TEXT_COLOR, .fontId = textId, .fontSize = TEXT_SIZE} {}

void ClayDisplayUi::draw(const DisplayInfo& info) const {
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
		drawRows(info);
	}
}

void ClayDisplayUi::drawRows(const DisplayInfo& info) const {
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
			drawChars(info, r);
		}
	}
}

void ClayDisplayUi::drawChars(const DisplayInfo& info, const int8_t row) const {
	for(int8_t c = 0; c < DISPLAY_LENGTH; c++) {
		const Clay_String charText = {
				.length = 1,
				.chars = &info.text[row][c],
		};

		CLAY({
				.layout{
						.sizing = {
								.width = CLAY_SIZING_FIT(40),
								.height = CLAY_SIZING_FIT(70),
						},
						.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				},
				.backgroundColor = info.blinkChar[0] == row && info.blinkChar[1] == c ? SELECTED_CHAR_COLOR : BASIC_CHAR_COLOR,
				.cornerRadius = {10, 10, 10, 10},
		}) {
			if(info.backlight) { CLAY_TEXT(charText, CLAY_TEXT_CONFIG(textConfig)); }
		}
	}
}
