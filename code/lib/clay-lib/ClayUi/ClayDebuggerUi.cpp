#include "ClayDebuggerUi.hpp"

ClayDebuggerUi::ClayDebuggerUi(const uint16_t id) {
	textId = id;
}

uint16_t ClayDebuggerUi::getDebuggerTextId() const {
	return textId;
}

void ClayDebuggerUi::createDebugger() {
	const Clay_TextElementConfig debugText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
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
		const Clay_String clayText = {
				.length = static_cast<int32_t>(text.length()),
				.chars = text.c_str(),
		};
		CLAY_TEXT(clayText, CLAY_TEXT_CONFIG(debugText));
	}
}

void ClayDebuggerUi::appendDebuggerText(const std::string& string) {
	//if(!text.empty())
	//	text.append("\n");
	text.append(string);
}
