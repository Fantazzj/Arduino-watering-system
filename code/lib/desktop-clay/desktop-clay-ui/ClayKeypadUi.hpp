#ifndef CLAY_KEYPAD_UI_HPP
#define CLAY_KEYPAD_UI_HPP

#include "clay.h"
#include <cstdint>
#include <string>

class ClayKeypadUi {
public:
	static constexpr Clay_Color BUTTONS_COLOR = {101, 157, 213, 255};
	static constexpr Clay_Color BG_COLOR = {100, 120, 150, 255};
	static constexpr Clay_Color TEXT_COLOR = {50, 50, 50, 255};
	static constexpr uint16_t TEXT_SIZE = 30;

	static constexpr std::string_view CANCEL_STRING = "Cancel";
	static constexpr std::string_view DOWN_STRING = "Down";
	static constexpr std::string_view UP_STRING = "Up";
	static constexpr std::string_view CONFIRM_STRING = "Confirm";

private:
	bool cancelState;
	bool downState;
	bool upState;
	bool confirmState;
	Clay_TextElementConfig textConfig;

public:
	explicit ClayKeypadUi(uint16_t textId);
	void draw() const;
	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	[[nodiscard]] bool getGeneralState() const;

private:
	void createButton(const std::string_view& name, const bool* clickVariable) const;
	static void updateVariable(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
};

#endif//CLAY_KEYPAD_UI_HPP
