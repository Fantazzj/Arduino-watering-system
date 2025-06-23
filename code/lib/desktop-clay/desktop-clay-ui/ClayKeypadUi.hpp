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
#if defined(MINGW) || defined(MSVC)
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif
	static constexpr std::string CANCEL_STRING = "Cancel";
	static constexpr std::string DOWN_STRING = "Down";
	static constexpr std::string UP_STRING = "Up";
	static constexpr std::string CONFIRM_STRING = "Confirm";

private:
	uint16_t textId;
	bool cancelState;
	bool downState;
	bool upState;
	bool confirmState;

public:
	explicit ClayKeypadUi(uint16_t textId);
	void createButtonGroup();
	[[nodiscard]] uint16_t getTextId() const;
	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	[[nodiscard]] bool getGeneralState() const;

private:
	void createButton(const std::string& name, const bool* clickVariable);
	static void updateVariable(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
};

#endif//CLAY_KEYPAD_UI_HPP
