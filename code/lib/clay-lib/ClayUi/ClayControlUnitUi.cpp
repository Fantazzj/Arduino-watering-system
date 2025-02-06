#include "ClayControlUnitUi.hpp"

extern "C" {
#include "clay.h"
}
#include "clay_renderer_raylib.c"
#include <iostream>

void HandleClayErrors(Clay_ErrorData errorData) {
	std::cout << errorData.errorText.chars << std::endl;
	exit(errorData.errorType);
}

ClayControlUnitUi::ClayControlUnitUi() :
	display(1), debugger(2), buttons(3), etvs(4) {
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
			.fontId = 0,
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", 28, nullptr, 250),
	};

	Raylib_fonts[1] = (Raylib_Font){
			.fontId = display.getDisplayTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/cour.ttf", DISPLAY_TEXT_SIZE, nullptr, 250),
	};

	Raylib_fonts[2] = (Raylib_Font){
			.fontId = debugger.getDebuggerTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/cour.ttf", DEBUGGER_TEXT_SIZE, nullptr, 250),
	};

	Raylib_fonts[3] = (Raylib_Font){
			.fontId = buttons.getButtonsTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/cour.ttf", BUTTONS_TEXT_SIZE, nullptr, 250),
	};

	Raylib_fonts[4] = (Raylib_Font){
			.fontId = etvs.getEtvsTextId(),
			.font = LoadFontEx("C:/Windows/Fonts/cour.ttf", ETVS_TEXT_SIZE, nullptr, 250),
	};

	Clay_SetMeasureTextFunction(Raylib_MeasureText, 0);

	//Clay_SetDebugModeEnabled(true);
}

void ClayControlUnitUi::createControlUnit() {
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

void ClayControlUnitUi::show() {
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

void ClayControlUnitUi::appendDebuggerText(std::string string) {
	debugger.appendDebuggerText(string);
}

void ClayControlUnitUi::setDisplayChar(int8_t row, int8_t col, char c) {
	display.setDisplayChar(row, col, c);
}

void ClayControlUnitUi::activateEtv(int8_t n) {
	etvs.setEtvState(n, true);
}

void ClayControlUnitUi::deactivateEtv(int8_t n) {
	etvs.setEtvState(n, false);
}

void ClayControlUnitUi::setKeypad(ClayKeypad* keypad) {
	buttons.setKeypad(keypad);
}
