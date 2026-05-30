#include "ClayDebuggerUi.hpp"

ClayDebuggerUi::ClayDebuggerUi(const uint16_t textId) :
	textConfig{.textColor = TEXT_COLOR, .fontId = textId, .fontSize = TEXT_SIZE} {}

void ClayDebuggerUi::draw(const DebuggerInfo& info) const {
	const Clay_String debugText = {
			.length = info.len,
			.chars = info.text,
	};

	CLAY({
			.id = CLAY_ID("Debugger"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.padding = {10, 10, 10, 10},
					.childGap = 0,
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
			.backgroundColor = BG_COLOR,
			.cornerRadius = {5, 5, 5, 5},
			.clip = {
					.vertical = true,
					.childOffset = Clay_GetScrollOffset(),
			},
	}) {
		CLAY_TEXT(debugText, CLAY_TEXT_CONFIG(textConfig));
	}
}
