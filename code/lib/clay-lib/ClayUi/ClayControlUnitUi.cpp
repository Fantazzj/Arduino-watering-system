#include "ClayControlUnitUi.hpp"

#include "clay_renderer_raylib.c"
#include <iostream>

void HandleClayErrors(Clay_ErrorData errorData) {
	std::cout << errorData.errorText.chars << std::endl;
	exit(errorData.errorType);
}

ClayControlUnitUi::ClayControlUnitUi() :
	display(1), etvs(2), buttons(3), debugger(4) {
	Clay_Raylib_Initialize(1500, 768, "ControlUnit", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

	const uint64_t clayRequiredMemory = Clay_MinMemorySize();
	const Clay_Arena clayMemory = {
			.capacity = clayRequiredMemory,
			.memory = static_cast<char*>(malloc(clayRequiredMemory)),
	};

	Clay_Initialize(
			clayMemory,
			(Clay_Dimensions) {
					.width = static_cast<float>(GetScreenWidth()),
					.height = static_cast<float>(GetScreenHeight()),
			},
			(Clay_ErrorHandler) {HandleClayErrors});

	Raylib_fonts[0] = {
			.fontId = 0,
			.font = LoadFontEx(ClayControlUnitUi::FONT, 28, nullptr, 250),
	};

	Raylib_fonts[1] = {
			.fontId = display.getDisplayTextId(),
			.font = LoadFontEx(ClayDisplayUi::FONT, ClayDisplayUi::TEXT_SIZE, nullptr, 250),
	};

	Raylib_fonts[2] = {
			.fontId = debugger.getDebuggerTextId(),
			.font = LoadFontEx(ClayDebuggerUi::FONT, ClayDebuggerUi::TEXT_SIZE, nullptr, 250),
	};

	Raylib_fonts[3] = {
			.fontId = buttons.getButtonsTextId(),
			.font = LoadFontEx(ClayKeypadUi::FONT, ClayKeypadUi::TEXT_SIZE, nullptr, 250),
	};

	Raylib_fonts[4] = {
			.fontId = etvs.getEtvsTextId(),
			.font = LoadFontEx(ClayValveGroupUi::FONT, ClayValveGroupUi::TEXT_SIZE, nullptr, 250),
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
		moisture.createMoistureGroup();
		etvs.createEtvGroup();
	}
}

void ClayControlUnitUi::show() {
	while(!WindowShouldClose()) {
		Clay_SetLayoutDimensions({
				.width = static_cast<float>(GetScreenWidth()),
				.height = static_cast<float>(GetScreenHeight()),
		});

		const Vector2 mousePosition = GetMousePosition();
		Clay_SetPointerState({mousePosition.x, mousePosition.y}, IsMouseButtonDown(0));

		const Vector2 scrollDelta = GetMouseWheelMoveV();
		Clay_UpdateScrollContainers(true, {scrollDelta.x, scrollDelta.y}, GetFrameTime());

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

		const Clay_RenderCommandArray renderCommands = Clay_EndLayout();

		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands);
		EndDrawing();
	}// !WindowShouldClose()
}

void ClayControlUnitUi::appendDebuggerText(const std::string& string) {
	debugger.appendDebuggerText(string);
}

void ClayControlUnitUi::setDisplayChar(const int8_t row, const int8_t col, const char c) {
	display.setDisplayChar(row, col, c);
}

void ClayControlUnitUi::activateEtv(const uint8_t n) {
	etvs.setEtvState(n, true);
}

void ClayControlUnitUi::deactivateEtv(const uint8_t n) {
	etvs.setEtvState(n, false);
}

void ClayControlUnitUi::setKeypad(ClayKeypad* keypad) {
	buttons.setKeypad(keypad);
}

void ClayControlUnitUi::activateMainSwitch() {
	etvs.setMainSwitchState(true);
}

void ClayControlUnitUi::deactivateMainSwitch() {
	etvs.setMainSwitchState(false);
}

void ClayControlUnitUi::setBlinkOn(const int8_t row, const int8_t col) {
	display.setBlinkOn(row, col);
}

uint8_t ClayControlUnitUi::getMoisture() const {
	return moisture.getMoisture();
}
