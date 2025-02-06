#include "clayUi.h"

#define CLAY_IMPLEMENTATION
#include "buttonsUi.h"
#include "clay.h"
#include "clay_renderer_raylib.c"
#include "debuggerUi.h"
#include "displayUi.h"
#include "etvsUi.h"
#include <stdlib.h>

static void HandleClayErrors(Clay_ErrorData errorData) {
	printf("%s", errorData.errorText.chars);
	exit(errorData.errorType);
}

void init() {
	Clay_Raylib_Initialize(1500, 768, "ControlUnit", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

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

	setEtvsTextId(3);
	Raylib_fonts[3] = (Raylib_Font){
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", ETVS_TEXT_SIZE, 0, 250),
			.fontId = getEtvsTextId(),
	};

	Clay_SetMeasureTextFunction(Raylib_MeasureText, 0);

	Clay_SetDebugModeEnabled(true);
}

static void createControlUnit() {
	CLAY(CLAY_ID("ControlUnit"),
		 CLAY_LAYOUT({.layoutDirection = CLAY_TOP_TO_BOTTOM,
					  .childGap = 25,
					  .sizing = {
							  .height = CLAY_SIZING_GROW(),
							  .width = CLAY_SIZING_FIT(),
					  }})) {
		createDisplay();
		createButtonGroup();
		createEtvGroup();
	}
}

void show() {
	appendDebuggerText(CLAY_STRING("A really long string to prove that the debugger can automatically go to new line if space ends"));
	appendDebuggerText(CLAY_STRING("A string to prove that the function appendDebuggerText() correctly appends text"));

	setDisplayChar(0, 0, 'E');
	setDisplayChar(0, 1, 'D');
	setDisplayChar(0, 2, 'I');
	setDisplayChar(0, 3, 'T');
	setDisplayChar(0, 4, 'E');
	setDisplayChar(0, 5, 'D');

	setEtvState(3, true);
	setEtvState(8, true);

	while(!WindowShouldClose()) {
		Clay_SetLayoutDimensions((Clay_Dimensions){
				.width = (float) GetScreenWidth(),
				.height = (float) GetScreenHeight(),
		});

		Vector2 mousePosition = GetMousePosition();
		Clay_SetPointerState((Clay_Vector2){mousePosition.x, mousePosition.y}, IsMouseButtonDown(0));

		Vector2 scrollDelta = GetMouseWheelMoveV();
		Clay_UpdateScrollContainers(true, (Clay_Vector2){scrollDelta.x, scrollDelta.y}, GetFrameTime());

		Clay_BeginLayout();

		CLAY(CLAY_ID("Container"),
			 CLAY_RECTANGLE({
					 .color = BG_COLOR,
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
