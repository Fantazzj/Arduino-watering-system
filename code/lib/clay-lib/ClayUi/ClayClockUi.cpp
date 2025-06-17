#include "ClayClockUi.hpp"

using std::chrono::system_clock;

ClayClockUi::ClayClockUi(const uint16_t id) {
	textId = id;
	dateTime = std::time(nullptr);
	localDateTime = std::localtime(&dateTime);
}

uint16_t ClayClockUi::getTextId() const {
	return textId;
}


void ClayClockUi::createClock() {
	CLAY({
			.id = CLAY_ID("Clock"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {
							.left = 10,
							.right = 10,
							.top = 10,
							.bottom = 10,
					},
					.childGap = 10,
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		createSpacer();
		createDateEditor();
		createSpacer();
		createTimeEditor();
		createSpacer();
	}
}

void ClayClockUi::createDateEditor() {
	const Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.childGap = 5,
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		createEditor(stringDateDay, 2);
		createEditor(stringDateMonth, 2);
		createEditor(stringDateYear, 4);
	}
}

void ClayClockUi::createTimeEditor() {
	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.childGap = 5,
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		createEditor(stringTimeHours, 2);
		createEditor(stringTimeMinutes, 2);
	}
}

void ClayClockUi::createEditor(const char* text, const int8_t len) {
	const Clay_TextElementConfig charText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	const Clay_String string = {.length = len, .chars = text};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.padding = {
							.left = 10,
							.right = 10,
					},
					.childGap = 5,
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
			.backgroundColor = CHAR_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		CLAY_TEXT(CLAY_STRING("+"), CLAY_TEXT_CONFIG(charText));
		CLAY_TEXT(string, CLAY_TEXT_CONFIG(charText));
		CLAY_TEXT(CLAY_STRING("-"), CLAY_TEXT_CONFIG(charText));
	}
}

void ClayClockUi::createSpacer() {
	CLAY({.layout = {
				  .sizing = {
						  .width = CLAY_SIZING_GROW(),
						  .height = CLAY_SIZING_FIT(),
				  }}}) {}
}
