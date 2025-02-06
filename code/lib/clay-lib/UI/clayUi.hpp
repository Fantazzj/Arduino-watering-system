#ifndef CLAYUI_H
#define CLAYUI_H

#define BG_COLOR {74, 95, 115, 255}

#include "clay.h"
#include <cstdint>

class ClayUi {
public:
	static void init();
	static void show();

	static void setDisplayChar(int8_t row, int8_t col, char c);
	static void appendDebuggerText(const char* string);
	static void activateEtv(int8_t n);
	static void deactivateEtv(int8_t n);

private:
	static void createControlUnit();
	static void HandleClayErrors(Clay_ErrorData errorData);
};

#endif//CLAYUI_H
