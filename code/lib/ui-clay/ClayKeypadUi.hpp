#pragma once

#include "clay.h"
#include <string>

typedef void (*ClayHandler_t)(Clay_ElementId, Clay_PointerData, intptr_t args);

struct KeypadInfo {
	ClayHandler_t cancelHandler;
	ClayHandler_t downHandler;
	ClayHandler_t upHandler;
	ClayHandler_t confirmHandler;
	intptr_t args;
};

class ClayKeypadUi {
	using string_view = std::string_view;

public:
	explicit ClayKeypadUi(uint16_t textId);
	void draw(const KeypadInfo& info) const;

	static constexpr uint16_t TEXT_SIZE = 30;

private:
	Clay_TextElementConfig textConfig;

	static constexpr Clay_Color BUTTONS_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};

	static constexpr string_view CANCEL_STRING = "Cancel";
	static constexpr string_view DOWN_STRING = "Down";
	static constexpr string_view UP_STRING = "Up";
	static constexpr string_view CONFIRM_STRING = "Confirm";

	void drawButton(const string_view& name, ClayHandler_t handler, intptr_t args) const;
};
