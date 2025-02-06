#ifndef CLAYUI_H
#define CLAYUI_H

#define BG_COLOR {74, 95, 115, 255}

#include "buttonsUi.hpp"
#include "debuggerUi.hpp"
#include "displayUi.hpp"
#include "etvsUi.hpp"
#include <cstdint>

class ClayUi {
public:
	ClayUi();
	void show();

	void setDisplayChar(int8_t row, int8_t col, char c);
	void appendDebuggerText(std::string string);
	void activateEtv(int8_t n);
	void deactivateEtv(int8_t n);

private:
	DisplayUi display;
	EtvsUi etvs;
	ButtonsUi buttons;
	DebuggerUi debugger;
	void createControlUnit();
};

#endif//CLAYUI_H
