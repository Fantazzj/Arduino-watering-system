#include "ClayUi.h"

#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "renderer/clay_renderer_raylib.c"
#include "stdlib.h"

void HandleClayErrors(Clay_ErrorData errorData) {
	printf("%s", errorData.errorText.chars);
}

void init() {
	Clay_Raylib_Initialize(800, 600, "ControlUnit", FLAG_WINDOW_RESIZABLE);

	uint64_t clayRequiredMemory = Clay_MinMemorySize();
	Clay_Arena clayMemory = (Clay_Arena){
			.capacity = clayRequiredMemory,
			.memory = (char*) malloc(clayRequiredMemory)};

	Clay_Initialize(clayMemory,
					(Clay_Dimensions){
							.width = (float) GetScreenWidth(),
							.height = (float) GetScreenHeight()},
					(Clay_ErrorHandler){HandleClayErrors});
}

void show() {
	while(!WindowShouldClose()) {
		Clay_BeginLayout();

		Clay_SetLayoutDimensions((Clay_Dimensions){
				.width = (float) GetScreenWidth(),
				.height = (float) GetScreenHeight()});

		CLAY(
				CLAY_RECTANGLE({.color = {0, 0, 255, 255}}),
				CLAY_LAYOUT({.sizing = {
									 .height = CLAY_SIZING_GROW(),
									 .width = CLAY_SIZING_GROW(),
							 }}));

		Clay_RenderCommandArray renderCommands = Clay_EndLayout();

		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands);
		EndDrawing();
	}
}
