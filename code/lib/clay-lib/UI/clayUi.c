#include "clayUi.h"

#define CLAY_IMPLEMENTATION
#include "buttonsUi.h"
#include "clay.h"
#include "clay_renderer_raylib.c"
#include "debuggerUi.h"
#include "displayUi.h"
#include <stdlib.h>

void HandleClayErrors(Clay_ErrorData errorData) {
	printf("%s", errorData.errorText.chars);
	exit(errorData.errorType);
}

void init() {
	Clay_Raylib_Initialize(1024, 768, "ControlUnit", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

	uint64_t clayRequiredMemory = Clay_MinMemorySize();
	Clay_Arena clayMemory = (Clay_Arena){
			.capacity = clayRequiredMemory,
			.memory = (char*) malloc(clayRequiredMemory),
	};

	Clay_Initialize(
			clayMemory,
			(Clay_Dimensions){
					.width = (float) GetScreenWidth(),
					.height = (float) GetScreenHeight(),
			},
			(Clay_ErrorHandler){HandleClayErrors});

	setDisplayTextId(0);
	Raylib_fonts[0] = (Raylib_Font){
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", DISPLAY_TEXT_SIZE, 0, 250),
			.fontId = getDisplayTextId(),
	};

	setDebuggerTextId(1);
	Raylib_fonts[1] = (Raylib_Font){
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", DEBUGGER_TEXT_SIZE, 0, 250),
			.fontId = getDebuggerTextId(),
	};

	setButtonsTextId(2);
	Raylib_fonts[2] = (Raylib_Font){
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", BUTTONS_TEXT_SIZE, 0, 250),
			.fontId = getButtonsTextId(),
	};

	Clay_SetMeasureTextFunction(Raylib_MeasureText, 0);
}

void createControlUnit() {
	CLAY(CLAY_ID("ControlUnit"),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .childGap = 5,
		 })) {
		createDisplay();
		//createEtvs();
		createButtonGroup();
	}
}

void show() {
	while(!WindowShouldClose()) {
		Clay_BeginLayout();

		Clay_SetLayoutDimensions((Clay_Dimensions){
				.width = (float) GetScreenWidth(),
				.height = (float) GetScreenHeight(),
		});

		CLAY(CLAY_ID("Container"),
			 CLAY_RECTANGLE({
					 .color = {209, 209, 209, 110},
			 }),
			 CLAY_LAYOUT({
					 .layoutDirection = CLAY_LEFT_TO_RIGHT,
					 .sizing = {
							 .height = CLAY_SIZING_GROW(),
							 .width = CLAY_SIZING_GROW(),
					 },
					 .padding = {25, 25, 25, 25},
					 .childGap = 25,
			 })) {
			createControlUnit();
			createDebugger();
		}

		Clay_RenderCommandArray renderCommands = Clay_EndLayout();

		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands);
		EndDrawing();
	}// !WindowShouldClose()
}
