#ifndef CLAY_CONTROL_UNIT_UI_HPP
#define CLAY_CONTROL_UNIT_UI_HPP

#include "ClayClockUi.hpp"
#include "ClayDebuggerUi.hpp"
#include "ClayDisplayUi.hpp"
#include "ClayKeypadUi.hpp"
#include "ClayMoistureUi.hpp"
#include "ClayValveGroupUi.hpp"
#include "raylib.h"

extern "C" {
#include "clay.h"
}

class ClayControlUnitUi {
public:
	static constexpr Clay_Color BG_COLOR = {74, 95, 115, 255};

public:
	ClayControlUnitUi();
	void show();
	void setDisplayChar(int8_t row, int8_t col, char c);
	void appendDebuggerText(const std::string& string);
	void activateEtv(uint8_t n);
	void deactivateEtv(uint8_t n);
	void activateMainSwitch();
	void deactivateMainSwitch();
	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	bool getGeneralState() const;
	void setBlinkOn(int8_t row, int8_t col);
	[[nodiscard]] uint8_t getMoisture() const;
	void setDateTime(std::chrono::local_time<std::chrono::seconds> dateTime);
	[[nodiscard]] std::chrono::local_time<std::chrono::seconds> getDateTime() const;

private:
	ClayDisplayUi display;
	ClayValveGroupUi etvs;
	ClayKeypadUi buttons;
	ClayDebuggerUi debugger;
	ClayMoistureUi moisture;
	ClayClockUi clock;
	Font fonts[6];
#if defined(MINGW) || defined(MSVC)
	static constexpr char FONT[] = "C:/Windows/Fonts/cour.ttf";
#else
	static constexpr char FONT[] = "/usr/share/fonts/jetbrains-mono-fonts/JetBrainsMono-Regular.otf";
#endif

	void createControlUnit();
	void createAdminSection();
	static void HandleClayErrors(Clay_ErrorData errorData);
};

#endif//CLAY_CONTROL_UNIT_UI_HPP
