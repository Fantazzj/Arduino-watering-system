#include "ClayKeypadUi.hpp"

ClayKeypadUi::ClayKeypadUi(const uint16_t id) {
	textId = id;
	for(int8_t i = 0; i < NUM; i++)
		handlers[i].num = i;
}

uint16_t ClayKeypadUi::getButtonsTextId() const {
	return textId;
}

void ClayKeypadUi::pressHandler(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;

	switch(const auto* data = reinterpret_cast<HandlerData*>(args); data->num) {
		case 0:
			data->keypad->cancelState = true;
			break;
		case 1:
			data->keypad->downState = true;
			break;
		case 2:
			data->keypad->upState = true;
			break;
		case 3:
			data->keypad->confirmState = true;
			break;
		default:
			break;
	}
}

void ClayKeypadUi::createButtonGroup() {
	CLAY(CLAY_ID("Buttons"),
		 CLAY_RECTANGLE({
				 .color = BG_COLOR,
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
		for(int8_t i = 0; i < NUM; i++)
			createButton(i);
	}
}

void ClayKeypadUi::createButton(const int8_t i) {
	const Clay_TextElementConfig buttonText = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
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
		 Clay_OnHover(pressHandler, reinterpret_cast<intptr_t>(&handlers[i]))) {
		const Clay_String buttonName = {
				.length = static_cast<int32_t>(buttonNames[i].length()),
				.chars = buttonNames[i].c_str(),
		};
		CLAY_TEXT(buttonName, CLAY_TEXT_CONFIG(buttonText));
	}
}

void ClayKeypadUi::setKeypad(ClayKeypad* keypad) {
	for(auto & handler : handlers)
		handler.keypad = keypad;
}
