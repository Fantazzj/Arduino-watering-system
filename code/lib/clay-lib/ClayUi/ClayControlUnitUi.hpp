#ifndef CLAY_CONTROL_UNIT_UI_HPP
#define CLAY_CONTROL_UNIT_UI_HPP

#include "../ClayKeypad.hpp"
#include "ClayDebuggerUi.hpp"
#include "ClayDisplayUi.hpp"
#include "ClayKeypadUi.hpp"
#include "ClayMoistureUi.hpp"
#include "ClayValveGroupUi.hpp"
#include <cstdint>

extern "C" {
#include "clay.h"
}

class ClayControlUnitUi {
public:
	static constexpr Clay_Color BG_COLOR = {74, 95, 115, 255};

public:
	ClayControlUnitUi();
	void show();
	void setDisplayChar(int8_t row, int8_t col, char c);
	void appendDebuggerText(std::string string);
	void activateEtv(int8_t n);
	void deactivateEtv(int8_t n);
	void activateMainSwitch();
	void deactivateMainSwitch();
	void setKeypad(ClayKeypad* keypad);
	void setBlinkOn(int8_t row, int8_t col);
	uint8_t getMoisture();

private:
	ClayDisplayUi display;
	ClayValveGroupUi etvs;
	ClayKeypadUi buttons;
	ClayDebuggerUi debugger;
	ClayMoistureUi moisture;
#ifdef WIN64
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif

	void createControlUnit();
};

#endif//CLAY_CONTROL_UNIT_UI_HPP