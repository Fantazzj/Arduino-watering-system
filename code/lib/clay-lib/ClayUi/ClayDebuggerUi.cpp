#include "ClayDebuggerUi.hpp"

ClayDebuggerUi::ClayDebuggerUi(const uint16_t textId) {
	this->textId = textId;
}

uint16_t ClayDebuggerUi::getDebuggerTextId() const {
	return textId;
}

void ClayDebuggerUi::createDebugger() {
	const Clay_TextElementConfig debugTextConfig = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	const Clay_String debugText = {
			.length = static_cast<int32_t>(text.length()),
			.chars = text.c_str(),
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
		CLAY_TEXT(debugText, CLAY_TEXT_CONFIG(debugTextConfig));
	}
}

void ClayDebuggerUi::appendDebuggerText(const std::string& string) {
	//if(!text.empty())
	//	text.append("\n");
	text.append(string);
}
