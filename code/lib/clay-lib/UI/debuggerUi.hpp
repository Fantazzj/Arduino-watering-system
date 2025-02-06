#ifndef DEBUGGERUI_H
#define DEBUGGERUI_H

#include "clay.h"

#include <cstdint>

#define DEBUGGER_BG_COLOR {100, 120, 150, 255}
#define DEBUGGER_TEXT_COLOR {50, 50, 50, 255}
#define DEBUGGER_TEXT_SIZE 30

class DebuggerUi {
public:
	static void createDebugger();
	static void setDebuggerTextId(uint16_t id);
	static uint16_t getDebuggerTextId();
	static void appendDebuggerText(Clay_String s);
};

#endif//DEBUGGERUI_H
