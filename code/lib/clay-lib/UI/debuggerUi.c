#include "debuggerUi.h"

#include "clay.h"

static uint16_t textId;

void setDebuggerTextId(uint16_t id) {
	textId = id;
}

uint16_t getDebuggerTextId(void) {
	return textId;
}

void createDebugger() {
	Clay_TextElementConfig debugText = {
			.fontId = textId,
			.fontSize = DEBUGGER_TEXT_SIZE,
			.textColor = DEBUGGER_TEXT_COLOR,
	};

	CLAY(CLAY_ID("Debugger"),
		 CLAY_RECTANGLE({
				 .color = DEBUGGER_BG_COLOR,
				 .cornerRadius = {5,5,5,5}
		 }),
		 CLAY_SCROLL({
				 .vertical = true,
		 }),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .sizing = {
						 .height = CLAY_SIZING_GROW(),
						 .width = CLAY_SIZING_GROW(),
				 },
				 .childGap = 0,
				 .padding = {10, 10, 10, 10},
		 })) {
		CLAY_TEXT(CLAY_STRING("A really much long string to prove that text automatically goes to new line"), CLAY_TEXT_CONFIG(debugText));
		CLAY_TEXT(CLAY_STRING("A really much long string to prove that text automatically goes to new line"), CLAY_TEXT_CONFIG(debugText));
		CLAY_TEXT(CLAY_STRING("A really much long string to prove that text automatically goes to new line"), CLAY_TEXT_CONFIG(debugText));
	}
}
