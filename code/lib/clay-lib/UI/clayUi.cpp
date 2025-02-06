#include "clayUi.hpp"

#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include <cstdlib>

void HandleClayErrors(Clay_ErrorData errorData) {
	printf("%s", errorData.errorText.chars);
	exit(errorData.errorType);
}

ClayUi::ClayUi() :
	display(0), debugger(1), buttons(2), etvs(3) {
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

	Raylib_fonts[0] = (Raylib_Font){
			.fontId = display.getDisplayTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", DISPLAY_TEXT_SIZE, 0, 250),
	};

	Raylib_fonts[1] = (Raylib_Font){
			.fontId = debugger.getDebuggerTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", DEBUGGER_TEXT_SIZE, 0, 250),
	};

	Raylib_fonts[2] = (Raylib_Font){
			.fontId = buttons.getButtonsTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", BUTTONS_TEXT_SIZE, 0, 250),
	};

	Raylib_fonts[3] = (Raylib_Font){
			.fontId = etvs.getEtvsTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", ETVS_TEXT_SIZE, 0, 250),
	};

	Clay_SetMeasureTextFunction(Raylib_MeasureText, 0);

	//Clay_SetDebugModeEnabled(true);
}

void ClayUi::createControlUnit() {
	CLAY(CLAY_ID("ControlUnit"),
		 CLAY_LAYOUT({
				 .sizing = {
						 .width = CLAY_SIZING_FIT(),
						 .height = CLAY_SIZING_GROW(),
				 },
				 .childGap = 25,
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
		 })) {
		display.createDisplay();
		buttons.createButtonGroup();
		etvs.createEtvGroup();
	}
}

void ClayUi::show() {
	//appendDebuggerText("A really long string to prove that the debugger can automatically go to new line if space ends");
	//appendDebuggerText("A string to prove that the function appendDebuggerText() correctly appends text");
	//appendDebuggerText("A string to prove that the function appendDebuggerLog() correctly converts the string");

	//setDisplayChar(0, 0, 'E');
	//setDisplayChar(0, 1, 'D');
	//setDisplayChar(0, 2, 'I');
	//setDisplayChar(0, 3, 'T');
	//setDisplayChar(0, 4, 'E');
	//setDisplayChar(0, 5, 'D');

	//activateEtv(3);
	//activateEtv(8);

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
					 .sizing = {
							 .width = CLAY_SIZING_GROW(),
							 .height = CLAY_SIZING_GROW(),
					 },
					 .padding = {25, 25, 25, 25},
					 .childGap = 25,
					 .layoutDirection = CLAY_LEFT_TO_RIGHT,
			 })) {
			createControlUnit();
			debugger.createDebugger();
		}

		Clay_RenderCommandArray renderCommands = Clay_EndLayout();

		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands);
		EndDrawing();
	}// !WindowShouldClose()
}

void ClayUi::appendDebuggerText(std::string string) {
	debugger.appendDebuggerText(string);
}

void ClayUi::setDisplayChar(int8_t row, int8_t col, char c) {
	display.setDisplayChar(row, col, c);
}

void ClayUi::activateEtv(int8_t n) {
	etvs.setEtvState(n, true);
}

void ClayUi::deactivateEtv(int8_t n) {
	etvs.setEtvState(n, false);
}
