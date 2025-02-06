#include "ClayDebuggerUi.hpp"

extern "C" {
#include "clay.h"
}

ClayDebuggerUi::ClayDebuggerUi(uint16_t id) {
	textId = id;
}

uint16_t ClayDebuggerUi::getDebuggerTextId() const {
	return textId;
}

void ClayDebuggerUi::createDebugger() {
	Clay_TextElementConfig debugText = {
			.textColor = DEBUGGER_TEXT_COLOR,
			.fontId = textId,
			.fontSize = DEBUGGER_TEXT_SIZE,
	};

	CLAY(CLAY_ID("Debugger"),
		 CLAY_RECTANGLE({
				 .color = DEBUGGER_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_SCROLL({
				 .vertical = true,
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .padding = {10, 10, 10, 10},
				 .childGap = 0,
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
		 })) {
		Clay_String clayText = {
				.length = static_cast<int32_t>(text.length()),
				.chars = text.c_str(),
		};
		CLAY_TEXT(clayText, CLAY_TEXT_CONFIG(debugText));
	}
}

void ClayDebuggerUi::appendDebuggerText(std::string string) {
	if(!text.empty())
		text.append("\n");
	text.append(string);
}
