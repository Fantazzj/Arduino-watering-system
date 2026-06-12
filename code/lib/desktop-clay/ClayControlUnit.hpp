#pragma once

#include "StdClock.hpp"
#include "StdDebugger.hpp"
#include "StdDisplay.hpp"
#include "StdKeypad.hpp"
#include "StdMainSwitch.hpp"
#include "StdMoisture.hpp"
#include "StdValveGroup.hpp"
#include "desktop-clay-ui/ClayControlUnitUi.hpp"

class ClayControlUnit {
public:
	explicit ClayControlUnit(StdDisplay& display, StdClock& clock, StdKeypad& keypad, StdValveGroup& valveGroup, StdMainSwitch& mainSwitch, StdMoisture& moisture, StdDebugger& debugger);
	void draw();

private:
	ClayControlUnitUi ui;

	StdDisplay& display;
	DisplayInfo displayInfo;
	StdClock& clock;
	ClockInfo clockInfo;
	StdKeypad& keypad;
	KeypadInfo keypadInfo;
	StdValveGroup& valveGroup;
	ValveGroupInfo valveGroupInfo;
	StdMainSwitch& mainSwitch;
	StdMoisture& moisture;
	MoistureInfo moistureInfo;
	StdDebugger& debugger;
	DebuggerInfo debuggerInfo;

	static void increaseOneDay(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void decreaseOneDay(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void increaseOneMonth(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void decreaseOneMonth(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void increaseOneYear(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void decreaseOneYear(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void increaseOneHour(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void decreaseOneHour(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void increaseOneMinute(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void decreaseOneMinute(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture00(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture10(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture20(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture30(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture40(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture50(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture60(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture70(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture80(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void setMoisture90(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void pressCancel(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void pressDown(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void pressUp(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
	static void pressConfirm(Clay_ElementId, Clay_PointerData pointerData, intptr_t args);
};
