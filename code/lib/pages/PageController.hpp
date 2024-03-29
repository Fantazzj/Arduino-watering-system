#ifndef PAGE_CONTROLLER_HPP
#define PAGE_CONTROLLER_HPP

#include "../core/AutoCycle.hpp"
#include "../core/Clock.hpp"
#include "../core/Keypad.hpp"
#include "../core/MainSwitch.hpp"
#include "../core/Memory.hpp"
#include "../core/UnitDisplay.hpp"
#include "../core/Valve.hpp"

enum KeypadButton : uint8_t {
	Cancel,
	Up,
	Down,
	Confirm,
	NoBtn
};

struct PageController {
	explicit PageController(Keypad* myKeypad, UnitDisplay* myDisplay, Clock* myClock, Valve* myEtv[], MainSwitch* myMainSwitch, Memory* myMemory, AutoCycle* autoCycle);
	Keypad* keypad;
	UnitDisplay* display;
	Clock* clock;
	Valve** etv;
	MainSwitch* mainSwitch;
	Memory* memory;
	AutoCycle* autoCycle;
	bool timeToEdit;
	uint8_t etvNum;
	KeypadButton keypadButton();

protected:
};

#endif
