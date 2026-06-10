#include "ClayControlUnitUi.hpp"

#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include <iostream>

void ClayControlUnitUi::HandleClayErrors(Clay_ErrorData errorData) {
	std::cout << errorData.errorText.chars << std::endl;
	exit(errorData.errorType);
}

ClayControlUnitUi::ClayControlUnitUi() :
	display(1), etvs(2), buttons(3), debugger(4), clock(5) {
	Clay_Raylib_Initialize(1500, 760, "ControlUnit", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

	const uint32_t clayRequiredMemory = Clay_MinMemorySize();
	const Clay_Arena clayMemory = {
			.capacity = clayRequiredMemory,
			.memory = new char[clayRequiredMemory],
	};

	Clay_Initialize(
			clayMemory,
			{
					.width = static_cast<float>(GetScreenWidth()),
					.height = static_cast<float>(GetScreenHeight()),
			},
			{HandleClayErrors});

	constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
	fonts[0] = LoadFontEx(FONT, 15, nullptr, 250);
	fonts[1] = LoadFontEx(FONT, ClayDisplayUi::TEXT_SIZE, nullptr, 250);
	fonts[2] = LoadFontEx(FONT, ClayDebuggerUi::TEXT_SIZE, nullptr, 250);
	fonts[3] = LoadFontEx(FONT, ClayKeypadUi::TEXT_SIZE, nullptr, 250);
	fonts[4] = LoadFontEx(FONT, ClayValveGroupUi::TEXT_SIZE, nullptr, 250);
	fonts[5] = LoadFontEx(FONT, ClayClockUi::TEXT_SIZE, nullptr, 250);

	Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

	//Clay_SetDebugModeEnabled(true);
}

void ClayControlUnitUi::createControlUnit(const ValveGroupInfo& valveGroupInfo) {
	CLAY({
			.id = CLAY_ID("ControlUnit"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_FIT(),
							.height = CLAY_SIZING_GROW(),
					},
					.childGap = 25,
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
	}) {
		display.draw(displayInfo);
		buttons.draw();
		moisture.createUi();
		etvs.draw(valveGroupInfo);
	}
}

void ClayControlUnitUi::drawAdminSection(const ClockInfo& clockInfo, const DebuggerInfo& debuggerInfo) const {
	CLAY({
			.id = CLAY_ID("Admin"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.childGap = 25,
					.layoutDirection = CLAY_TOP_TO_BOTTOM,
			},
	}) {
		clock.draw(clockInfo);
		debugger.draw(debuggerInfo);
	}
}


void ClayControlUnitUi::draw(const ClockInfo& clockInfo, const ValveGroupInfo& valveGroupInfo, const DebuggerInfo& debuggerInfo) {
	if(WindowShouldClose()) {
		Clay_Raylib_Close();
		return;
	}

	Clay_SetLayoutDimensions({
			.width = static_cast<float>(GetScreenWidth()),
			.height = static_cast<float>(GetScreenHeight()),
	});

	const Vector2 mousePosition = GetMousePosition();
	Clay_SetPointerState({mousePosition.x, mousePosition.y}, IsMouseButtonDown(0));

	const Vector2 scrollDelta = GetMouseWheelMoveV();
	Clay_UpdateScrollContainers(true, {scrollDelta.x, scrollDelta.y}, GetFrameTime());

	Clay_BeginLayout();

	CLAY({
			.id = CLAY_ID("Container"),
			.layout = {
					.sizing = {
							.width = CLAY_SIZING_GROW(),
							.height = CLAY_SIZING_GROW(),
					},
					.padding = CLAY_PADDING_ALL(25),
					.childGap = 25,
					.layoutDirection = CLAY_LEFT_TO_RIGHT,
			},
			.backgroundColor = BG_COLOR,
	}) {
		createControlUnit(valveGroupInfo);
		drawAdminSection(clockInfo, debuggerInfo);
	}

	const Clay_RenderCommandArray renderCommands = Clay_EndLayout();

	BeginDrawing();
	ClearBackground(BLACK);
	Clay_Raylib_Render(renderCommands, fonts);
	EndDrawing();
}

void ClayControlUnitUi::setDisplayChar(const int8_t row, const int8_t col, const char c) {
	displayInfo.text[row][col] = c;
}

void ClayControlUnitUi::setBacklight(const bool state) {
	displayInfo.backlight = state;
}

bool ClayControlUnitUi::getBacklight() const {
	return displayInfo.backlight;
}

bool ClayControlUnitUi::getCancelState() {
	return buttons.getCancelState();
}

bool ClayControlUnitUi::getDownState() {
	return buttons.getDownState();
}

bool ClayControlUnitUi::getUpState() {
	return buttons.getUpState();
}

bool ClayControlUnitUi::getConfirmState() {
	return buttons.getConfirmState();
}

bool ClayControlUnitUi::getGeneralState() const {
	return buttons.getGeneralState();
}

void ClayControlUnitUi::setBlinkOn(const int8_t row, const int8_t col) {
	displayInfo.blinkChar[0] = row;
	displayInfo.blinkChar[1] = col;
}

uint8_t ClayControlUnitUi::getMoisture() const {
	return moisture.getMoistureLevel();
}
