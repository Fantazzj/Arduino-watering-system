#include "debuggerUi.hpp"

#include "clay.h"

#include <cstdlib>

static uint16_t textId;

static Clay_String text = {
		.length = 0,
		.chars = nullptr,
};

void DebuggerUi::setDebuggerTextId(uint16_t id) {
	textId = id;
}

uint16_t DebuggerUi::getDebuggerTextId() {
	return textId;
}

void DebuggerUi::createDebugger() {
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
		CLAY_TEXT(text, CLAY_TEXT_CONFIG(debugText));
	}
}

void DebuggerUi::appendDebuggerText(Clay_String s) {
	bool newLine = text.length > 0;

	int32_t newLength = text.length + s.length + newLine;
	char* newChars = (char*) malloc(newLength);

	int32_t i = 0;
	for(int32_t j = 0; j < text.length; j++) {
		newChars[i] = text.chars[j];
		i++;
	}

	if(newLine) {
		newChars[i] = '\n';
		i++;
	}

	for(int32_t j = 0; j < s.length; j++) {
		newChars[i] = s.chars[j];
		i++;
	}

	text.length = newLength;
	free((char*) text.chars);
	text.chars = newChars;
}
