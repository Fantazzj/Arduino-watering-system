#ifndef CLAY_RENDERER_RAYLIB_H
#define CLAY_RENDERER_RAYLIB_H

#include "clay.h"

void Clay_Raylib_Initialize(int width, int height, const char* title, unsigned int flags);
extern Clay_Dimensions Raylib_MeasureText(Clay_StringSlice text, Clay_TextElementConfig* config, void* userData);
void Clay_Raylib_Render(Clay_RenderCommandArray renderCommands, Font* fonts);

#endif
