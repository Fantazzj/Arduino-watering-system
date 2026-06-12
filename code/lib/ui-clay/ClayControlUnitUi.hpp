#pragma once

#include "ClayDebuggerUi.hpp"
#include "ClayDisplayUi.hpp"
#include "ClayKeypadUi.hpp"
#include "ClayMoistureUi.hpp"
#include "ClayValveGroupUi.hpp"
#include "ClayClockUi.hpp"
#include "raylib.h"

class ClayControlUnitUi {
public:
	ClayControlUnitUi();
	void draw(const DisplayInfo& displayInfo, const ClockInfo& clockInfo, const KeypadInfo& keypadInfo, const ValveGroupInfo& valveGroupInfo, const MoistureInfo& moistureInfo, const DebuggerInfo& debuggerInfo);

private:
	static constexpr Clay_Color BG_COLOR = {74, 95, 115, 255};

	ClayDisplayUi display;
	ClayValveGroupUi etvs;
	ClayKeypadUi buttons;
	ClayDebuggerUi debugger;
	ClayMoistureUi moisture;
	ClayClockUi clock;
	Font fonts[6];

	void createControlUnit(const DisplayInfo& displayInfo, const KeypadInfo& keypadInfo, const ValveGroupInfo& valveGroupInfo, const MoistureInfo& moistureInfo);
	void drawAdminSection(const ClockInfo& clockInfo, const DebuggerInfo& debuggerInfo) const;
	static void HandleClayErrors(Clay_ErrorData errorData);
};
