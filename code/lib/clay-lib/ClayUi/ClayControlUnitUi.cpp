#include "ClayControlUnitUi.hpp"

extern "C" {
#include "clay_renderer_raylib.h"
}
#include <iostream>

void ClayControlUnitUi::HandleClayErrors(Clay_ErrorData errorData) {
	std::cout << errorData.errorText.chars << std::endl;
	exit(errorData.errorType);
}

ClayControlUnitUi::ClayControlUnitUi() :
	display(1), etvs(2), buttons(3), debugger(4), clock(5) {
	Clay_Raylib_Initialize(1500, 760, "ControlUnit", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

	const uint64_t clayRequiredMemory = Clay_MinMemorySize();
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

	fonts[0] = LoadFontEx(ClayControlUnitUi::FONT, 15, nullptr, 250);
	fonts[1] = LoadFontEx(ClayDisplayUi::FONT, ClayDisplayUi::TEXT_SIZE, nullptr, 250);
	fonts[2] = LoadFontEx(ClayDebuggerUi::FONT, ClayDebuggerUi::TEXT_SIZE, nullptr, 250);
	fonts[3] = LoadFontEx(ClayKeypadUi::FONT, ClayKeypadUi::TEXT_SIZE, nullptr, 250);
	fonts[4] = LoadFontEx(ClayValveGroupUi::FONT, ClayValveGroupUi::TEXT_SIZE, nullptr, 250);
	fonts[5] = LoadFontEx(ClayClockUi::FONT, ClayClockUi::TEXT_SIZE, nullptr, 250);

	Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

	Clay_SetDebugModeEnabled(true);
}

void ClayControlUnitUi::createControlUnit() {
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
		display.createDisplay();
		buttons.createButtonGroup();
		moisture.createMoistureGroup();
		etvs.createEtvGroup();
	}
}

void ClayControlUnitUi::createAdminSection() {
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
		clock.createClock();
		debugger.createUi();
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

		CLAY({
				.id = CLAY_ID("Container"),
				.layout = {
						.sizing = {
								.width = CLAY_SIZING_GROW(),
								.height = CLAY_SIZING_GROW(),
						},
						.padding = {25, 25, 25, 25},
						.childGap = 25,
						.layoutDirection = CLAY_LEFT_TO_RIGHT,
				},
				.backgroundColor = BG_COLOR,
		}) {
			createControlUnit();
			createAdminSection();
		}

		const Clay_RenderCommandArray renderCommands = Clay_EndLayout();

		BeginDrawing();
		ClearBackground(BLACK);
		Clay_Raylib_Render(renderCommands, fonts);
		EndDrawing();
	}// !WindowShouldClose()
}

void ClayControlUnitUi::appendDebuggerText(const std::string& string) {
	debugger.appendText(string);
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

void ClayControlUnitUi::setDateTime(const std::chrono::local_time<std::chrono::seconds> dateTime) {
	clock.setDateTime(dateTime);
}

std::chrono::local_time<std::chrono::seconds> ClayControlUnitUi::getDateTime() const {
	return clock.getDateTime();
}
