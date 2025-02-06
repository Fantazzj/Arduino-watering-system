#ifndef CLAYUI_H
#define CLAYUI_H

#define BG_COLOR {74, 95, 115, 255}

#include <stdint.h>

void init(void);
void show(void);

void setDisplayChar(int8_t row, int8_t col, char c);
void appendDebuggerLog(const char* string);
void activateEtv(int8_t n);
void deactivateEtv(int8_t n);

#endif//CLAYUI_H
