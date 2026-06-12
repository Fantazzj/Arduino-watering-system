#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayClock.hpp"
#include "ClayDebugger.hpp"
#include "ClayDisplay.hpp"
#include "ClayMainSwitch.hpp"
#include "ClayMoisture.hpp"
#include "ClayValveGroup.hpp"
#include "desktop-clay-ui/ClayControlUnitUi.hpp"

class ClayControlUnit {
public:
	explicit ClayControlUnit(ClayDisplay& display, ClayClock& clock, ClayValveGroup& valveGroup, ClayMainSwitch& mainSwitch, ClayMoisture& moisture, ClayDebugger& debugger);
	void draw();

	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	[[nodiscard]] bool getGeneralState() const;

private:
	ClayControlUnitUi ui;

	ClayDisplay& display;
	DisplayInfo displayInfo;
	ClayClock& clock;
	ClockInfo clockInfo;
	ClayValveGroup& valveGroup;
	ValveGroupInfo valveGroupInfo;
	ClayMainSwitch& mainSwitch;
	ClayMoisture& moisture;
	MoistureInfo moistureInfo;
	ClayDebugger& debugger;
	DebuggerInfo debuggerInfo;

	static void increaseOneDay(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneDay(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneMonth(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneMonth(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneYear(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneYear(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneHour(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneHour(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void increaseOneMinute(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void decreaseOneMinute(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture00(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture10(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture20(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture30(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture40(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture50(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture60(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture70(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture80(Clay_ElementId, Clay_PointerData, intptr_t args);
	static void setMoisture90(Clay_ElementId, Clay_PointerData, intptr_t args);
};


#endif//CLAYCONTROLUNIT_HPP
