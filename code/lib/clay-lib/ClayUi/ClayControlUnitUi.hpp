#ifndef CLAY_CONTROL_UNIT_UI_HPP
#define CLAY_CONTROL_UNIT_UI_HPP

#define BG_COLOR {74, 95, 115, 255}

#include "../ClayKeypad.hpp"
#include "ClayDebuggerUi.hpp"
#include "ClayDisplayUi.hpp"
#include "ClayKeypadUi.hpp"
#include "ClayValveGroupUi.hpp"
#include <cstdint>

class ClayControlUnitUi {
public:
	ClayControlUnitUi();
	void show();
	void setDisplayChar(int8_t row, int8_t col, char c);
	void appendDebuggerText(std::string string);
	void activateEtv(int8_t n);
	void deactivateEtv(int8_t n);
	void setKeypad(ClayKeypad* keypad);

private:
	ClayDisplayUi display;
	ClayValveGroupUi etvs;
	ClayKeypadUi buttons;
	ClayDebuggerUi debugger;
	void createControlUnit();
};

#endif//CLAY_CONTROL_UNIT_UI_HPP
