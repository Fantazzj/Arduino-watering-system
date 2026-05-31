#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayClock.hpp"
#include "ClayDebugger.hpp"
#include "desktop-clay-ui/ClayControlUnitUi.hpp"

class ClayControlUnit {
public:
	explicit ClayControlUnit(ClayClock& clock, ClayDebugger& debugger);
	void draw();

	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	[[nodiscard]] bool getGeneralState() const;
	void activateEtv(uint8_t n);
	void deactivateEtv(uint8_t n);
	void activateMainSwitch();
	void deactivateMainSwitch();
	void debuggerLog(const std::string& string);
	void printOnDisplay(const std::string& text);
	void setCursorDisplay(int8_t x, int8_t y);
	void clearDisplay();
	void hideCursorDisplay();
	void showCursorDisplay();
	void setBacklight(bool state);
	[[nodiscard]] bool getBacklight() const;
	[[nodiscard]] uint8_t getMoisture() const;

private:
	ClayControlUnitUi ui;
	int8_t x = 0;
	int8_t y = 0;

	ClayClock& clock;
	ClockInfo clockInfo;
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
};


#endif//CLAYCONTROLUNIT_HPP
