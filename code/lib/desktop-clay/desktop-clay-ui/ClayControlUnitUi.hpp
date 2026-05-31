#ifndef CLAY_CONTROL_UNIT_UI_HPP
#define CLAY_CONTROL_UNIT_UI_HPP

#include "ClayClockUi.hpp"
#include "ClayDebuggerUi.hpp"
#include "ClayDisplayUi.hpp"
#include "ClayKeypadUi.hpp"
#include "ClayMoistureUi.hpp"
#include "ClayValveGroupUi.hpp"
#include "raylib.h"

#include "clay.h"

class ClayControlUnitUi {
public:
	ClayControlUnitUi();
	void draw(const ClockInfo& clockInfo, const DebuggerInfo& debuggerInfo);
	void setDisplayChar(int8_t row, int8_t col, char c);
	void setBacklight(bool state);
	[[nodiscard]] bool getBacklight() const;
	void activateEtv(uint8_t n);
	void deactivateEtv(uint8_t n);
	void activateMainSwitch();
	void deactivateMainSwitch();
	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	[[nodiscard]] bool getGeneralState() const;
	void setBlinkOn(int8_t row, int8_t col);
	[[nodiscard]] uint8_t getMoisture() const;

private:
	static constexpr Clay_Color BG_COLOR = {74, 95, 115, 255};

	ClayDisplayUi display;
	ClayValveGroupUi etvs;
	ClayKeypadUi buttons;
	ClayDebuggerUi debugger;
	ClayMoistureUi moisture;
	ClayClockUi clock;
	Font fonts[6];

	ValveGroupInfo valveGroupInfo;
	DisplayInfo displayInfo;

	void createControlUnit();
	void drawAdminSection(const ClockInfo& clockInfo, const DebuggerInfo& debuggerInfo) const;
	static void HandleClayErrors(Clay_ErrorData errorData);

	void updateStrings();
};

#endif//CLAY_CONTROL_UNIT_UI_HPP
