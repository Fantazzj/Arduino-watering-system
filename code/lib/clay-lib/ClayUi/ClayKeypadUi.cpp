#include "ClayKeypadUi.hpp"

ClayKeypadUi::ClayKeypadUi(uint16_t id) {
	textId = id;
}

uint16_t ClayKeypadUi::getButtonsTextId() const {
	return textId;
}

ClayKeypad* keypad = nullptr;

static void pressHandler(Clay_ElementId, Clay_PointerData pointerData, intptr_t i) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;

	switch(i) {
		case 0:
			keypad->cancelState = true;
			break;
		case 1:
			keypad->downState = true;
			break;
		case 2:
			keypad->upState = true;
			break;
		case 3:
			keypad->confirmState = true;
			break;
		default:
			break;
	}
}

void ClayKeypadUi::createButton(int8_t i) {
	Clay_TextElementConfig buttonText = {
			.textColor = BUTTONS_TEXT_COLOR,
			.fontId = textId,
			.fontSize = BUTTONS_TEXT_SIZE,
	};

	CLAY(CLAY_RECTANGLE({
				 .color = BUTTONS_COLOR,
				 .cornerRadius = {10, 10, 10, 10},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
		 }),
		 Clay_OnHover(pressHandler, i)) {
		Clay_String buttonName = {
				.length = static_cast<int32_t>(buttonNames[i].length()),
				.chars = buttonNames[i].c_str(),
		};
		CLAY_TEXT(buttonName, CLAY_TEXT_CONFIG(buttonText));
	}
}

void ClayKeypadUi::createButtonGroup() {
	CLAY(CLAY_ID("Buttons"),
		 CLAY_RECTANGLE({
				 .color = BUTTONS_BG_COLOR,
				 .cornerRadius = {5, 5, 5, 5},
		 }),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_GROW(),
						 .height = CLAY_SIZING_FIXED(150),
				 },
				 .padding = {10, 10, 10, 10},
				 .childGap = 10,
				 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
				 .layoutDirection = CLAY_LEFT_TO_RIGHT,
		 })) {
		for(int8_t i = 0; i < BUTTONS_NUM; i++)
			createButton(i);
	}
}

void ClayKeypadUi::setKeypad(ClayKeypad* keypad) {
	::keypad = keypad;
}
