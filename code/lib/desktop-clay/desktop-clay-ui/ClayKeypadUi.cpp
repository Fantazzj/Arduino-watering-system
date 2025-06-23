#include "ClayKeypadUi.hpp"

using namespace std;

ClayKeypadUi::ClayKeypadUi(const uint16_t textId) {
	this->textId = textId;
	cancelState = false;
	downState = false;
	upState = false;
	confirmState = false;
}

uint16_t ClayKeypadUi::getTextId() const {
	return textId;
}

void ClayKeypadUi::updateVariable(Clay_ElementId, const Clay_PointerData pointerData, const intptr_t args) {
	if(pointerData.state != CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
		return;

	const auto clickVariable = reinterpret_cast<bool*>(args);
	*clickVariable = true;
}

bool ClayKeypadUi::getCancelState() {
	const bool state = cancelState;
	cancelState = false;
	return state;
}

bool ClayKeypadUi::getDownState() {
	const bool state = downState;
	downState = false;
	return state;
}

bool ClayKeypadUi::getUpState() {
	const bool state = upState;
	upState = false;
	return state;
}

bool ClayKeypadUi::getConfirmState() {
	const bool state = confirmState;
	confirmState = false;
	return state;
}

bool ClayKeypadUi::getGeneralState() const {
	return cancelState || downState || upState || confirmState;
}


void ClayKeypadUi::createButtonGroup() {
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
		createButton(CANCEL_STRING, &cancelState);
		createButton(DOWN_STRING, &downState);
		createButton(UP_STRING, &upState);
		createButton(CONFIRM_STRING, &confirmState);
	}
}

void ClayKeypadUi::createButton(const string& name, const bool* clickVariable) {
	const Clay_TextElementConfig textConfig = {
			.textColor = TEXT_COLOR,
			.fontId = textId,
			.fontSize = TEXT_SIZE,
	};

	const Clay_String buttonName = {
			.length = static_cast<int32_t>(name.length()),
			.chars = name.c_str(),
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
		Clay_OnHover(updateVariable, reinterpret_cast<intptr_t>(clickVariable));
		CLAY_TEXT(buttonName, CLAY_TEXT_CONFIG(textConfig));
	}
}
