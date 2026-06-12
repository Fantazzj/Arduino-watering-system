#include "ClayClockUi.hpp"

ClayClockUi::ClayClockUi(const uint16_t textId) :
	textConfig{.textColor = TEXT_COLOR, .fontId = textId, .fontSize = TEXT_SIZE} {}

void ClayClockUi::draw(const ClockInfo& info) const {
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
		drawSpacer();
		drawDateEditor(info);
		drawSpacer();
		drawTimeEditor(info);
		drawSpacer();
	}
}

void ClayClockUi::drawDateEditor(const ClockInfo& info) const {
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
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = CHAR_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		drawEditor(info, info.DateDay, 2, info.increaseOneDay, info.decreaseOneDay);
		CLAY_TEXT(CLAY_STRING("/"), CLAY_TEXT_CONFIG(textConfig));
		drawEditor(info, info.DateMonth, 2, info.increaseOneMonth, info.decreaseOneMonth);
		CLAY_TEXT(CLAY_STRING("/"), CLAY_TEXT_CONFIG(textConfig));
		drawEditor(info, info.DateYear, 4, info.increaseOneYear, info.decreaseOneYear);
	}
}

void ClayClockUi::drawTimeEditor(const ClockInfo& info) const {
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
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = CHAR_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		drawEditor(info, info.TimeHours, 2, info.increaseOneHour, info.decreaseOneHour);
		CLAY_TEXT(CLAY_STRING(":"), CLAY_TEXT_CONFIG(textConfig));
		drawEditor(info, info.TimeMinutes, 2, info.increaseOneMinute, info.decreaseOneMinute);
	}
}

void ClayClockUi::drawEditor(const ClockInfo& info, const char* num, const int8_t len, const ClayHandler_t pressHandlerAdd, const ClayHandler_t pressHandlerSub) const {
	const Clay_String string = {
			.length = static_cast<int32_t>(len),
			.chars = num,
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_FIT(),
					},
					.childAlignment = {
							.x = CLAY_ALIGN_X_CENTER,
							.y = CLAY_ALIGN_Y_CENTER,
					},
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
	}) {
		CLAY() {
			Clay_OnHover(pressHandlerAdd, info.args);
			CLAY_TEXT(CLAY_STRING("+"), CLAY_TEXT_CONFIG(textConfig));
		}
		CLAY_TEXT(string, CLAY_TEXT_CONFIG(textConfig));
		CLAY() {
			Clay_OnHover(pressHandlerSub, info.args);
			CLAY_TEXT(CLAY_STRING("-"), CLAY_TEXT_CONFIG(textConfig));
		}
	}
}

void ClayClockUi::drawSpacer() const {
	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIT(),
					},
			},
	}) {}
}
