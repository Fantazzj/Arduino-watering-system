#include "ClayKeypadUi.hpp"

using namespace std;

ClayKeypadUi::ClayKeypadUi(const uint16_t textId) :
	textConfig{.textColor = TEXT_COLOR, .fontId = textId, .fontSize = TEXT_SIZE} {}

void ClayKeypadUi::draw(const KeypadInfo& info) const {
	CLAY({
			.id = CLAY_ID("Buttons"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_FIXED(150),
					},
					.padding = {10, 10, 10, 10},
					.childGap = 10,
					.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {5, 5, 5, 5},
	}) {
		drawButton(CANCEL_STRING, info.cancelHandler, info.args);
		drawButton(DOWN_STRING, info.downHandler, info.args);
		drawButton(UP_STRING, info.upHandler, info.args);
		drawButton(CONFIRM_STRING, info.confirmHandler, info.args);
	}
}

void ClayKeypadUi::drawButton(const string_view& name, const ClayHandler_t handler, const intptr_t args) const {
	const Clay_String buttonName = {
			.length = static_cast<int32_t>(name.length()),
			.chars = name.data(),
	};

	CLAY({
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			},
			.backgroundColor = BUTTONS_COLOR,
			.cornerRadius = {10, 10, 10, 10},
	}) {
		Clay_OnHover(handler, args);
		CLAY_TEXT(buttonName, CLAY_TEXT_CONFIG(textConfig));
	}
}
