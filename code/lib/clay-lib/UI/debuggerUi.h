#ifndef DEBUGGERUI_H
#define DEBUGGERUI_H

#include <stdint.h>

#define DEBUGGER_BG_COLOR {100, 120, 150, 255}
#define DEBUGGER_TEXT_COLOR {50, 50, 50, 255}
#define DEBUGGER_TEXT_SIZE 30

void createDebugger(void);

void setDebuggerTextId(uint16_t id);
uint16_t getDebuggerTextId(void);

#endif//DEBUGGERUI_H
