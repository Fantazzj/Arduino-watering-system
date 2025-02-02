#ifndef DEBUGGERUI_H
#define DEBUGGERUI_H

#include <stdint.h>

#define DEBUGGER_BG_COLOR {255, 0, 0, 255}
#define DEBUGGER_TEXT_COLOR {255, 255, 255, 255}
#define DEBUGGER_TEXT_SIZE 30

void createDebugger(void);

void setDebuggerTextId(uint16_t id);
uint16_t getDebuggerTextId(void);

#endif//DEBUGGERUI_H
