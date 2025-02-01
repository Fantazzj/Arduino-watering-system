#include "clayUi.h"

#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include <stdlib.h>

#define CHILD (void) NULL

#define D_HEIGHT 2
#define D_LENGHT 16

const char text[D_HEIGHT][D_LENGHT] = {
		"simple text row1",
		"simple text row2",
};

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

	Raylib_fonts[0] = (Raylib_Font){
			.font = LoadFontEx("C:/Windows/Fonts/arial.ttf", 48, 0, 400),
			.fontId = 0,
	};
	Clay_SetMeasureTextFunction(Raylib_MeasureText, 0);
}

void createDisplayChars(int8_t row, int8_t columns) {
	Clay_Sizing charSize = {
			.height = CLAY_SIZING_FIXED(50),
			.width = CLAY_SIZING_FIXED(35),
	};

	Clay_Color charBgColor = {
			255,
			0,
			0,
			255,
	};

	Clay_TextElementConfig charText = {
			.fontId = 0,
			.fontSize = 48,
			.textColor = {255, 255, 255, 255},
	};

	for(int8_t c = 0; c < columns; c++) {
		Clay_String displayText = {
				.chars = text[row] + c,
				.length = 1,
		};

		CLAY(CLAY_RECTANGLE(
					 {.color = charBgColor}),
			 CLAY_LAYOUT({
					 .sizing = charSize,
					 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
			 }),
			 CHILD) {
			CLAY_TEXT(displayText, CLAY_TEXT_CONFIG(charText));
		}
	}
}

void createDisplayRows(int8_t rows, int8_t columns) {
	Clay_Sizing rowSize = {
			.height = CLAY_SIZING_FIT(),
			.width = CLAY_SIZING_FIT(),
	};

	for(int8_t r = 0; r < rows; r++) {
		CLAY(CLAY_LAYOUT({
					 .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
					 .childGap = 5,
					 .sizing = rowSize,
			 }),
			 CHILD) {
			createDisplayChars(r, columns);
		}
	}
}

void createDisplay(int8_t rows, int8_t columns) {
	CLAY(CLAY_ID("Display"),
		 CLAY_RECTANGLE({.color = {209, 209, 209, 220}}),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .sizing = {
						 .height = CLAY_SIZING_FIT(),
						 .width = CLAY_SIZING_FIT(),
				 },
				 .childGap = 5,
				 .padding = {5, 5, 5, 5},
		 }),
		 CHILD) {
		createDisplayRows(rows, columns);
	}
}

void createControlUnit() {
	createDisplay(D_HEIGHT, D_LENGHT);
	//createButtons();
	//createEtvs();
}

void createDebugger() {
	Clay_TextElementConfig debugText = {
			.fontId = 0,
			.fontSize = 30,
			.textColor = {255, 255, 255, 255},
	};

	CLAY(CLAY_ID("Debugger"),
		 CLAY_RECTANGLE({.color = {255, 0, 0, 255}}),
		 CLAY_SCROLL({.vertical = true}),
		 CLAY_LAYOUT({
				 .layoutDirection = CLAY_TOP_TO_BOTTOM,
				 .sizing = {
						 .height = CLAY_SIZING_GROW(),
						 .width = CLAY_SIZING_GROW(),
				 },
				 .childGap = 5,
				 .padding = {5, 5, 5, 5},
		 }),
		 CHILD) {
		CLAY_TEXT(CLAY_STRING("A really much long string to prove that text automatically goes to new line"), CLAY_TEXT_CONFIG(debugText));
		CLAY_TEXT(CLAY_STRING("A really much long string to prove that text automatically goes to new line"), CLAY_TEXT_CONFIG(debugText));
		CLAY_TEXT(CLAY_STRING("A really much long string to prove that text automatically goes to new line"), CLAY_TEXT_CONFIG(debugText));
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
			 CLAY_RECTANGLE({.color = {209, 209, 209, 110}}),
			 CLAY_LAYOUT({
					 .layoutDirection = CLAY_LEFT_TO_RIGHT,
					 .sizing =
							 {
									 .height = CLAY_SIZING_GROW(),
									 .width = CLAY_SIZING_GROW(),
							 },
					 .padding = {25, 25, 25, 25},
					 .childGap = 25,
			 }),
			 CHILD) {
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
