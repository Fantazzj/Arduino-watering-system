#include "debuggerUi.h"

#include "clay.h"

#include <stdlib.h>

static uint16_t textId;

static Clay_String text = {
		.chars = NULL,
		.length = 0,
};

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
				 .cornerRadius = {5, 5, 5, 5},
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
		CLAY_TEXT(text, CLAY_TEXT_CONFIG(debugText));
	}
}

void appendDebuggerText(Clay_String s) { //TODO: solve problem about firs newline
	int32_t newLength = text.length + s.length + 1;
	char* newChars = (char*) malloc(newLength);

	int32_t i = 0;
	for(int32_t j = 0; j < text.length; j++) {
		newChars[i] = text.chars[j];
		i++;
	}

	newChars[i] = '\n';
	i++;

	for(int32_t j = 0; j < s.length; j++) {
		newChars[i] = s.chars[j];
		i++;
	}

	text.length = newLength;
	free((char*) text.chars);
	text.chars = newChars;
}
