#ifndef PAGE_CONTROLLER_HPP
#define PAGE_CONTROLLER_HPP

#include "../core-lib/AutoCycle.hpp"
#include "../core-lib/Clock.hpp"
#include "../core-lib/Keypad.hpp"
#include "../core-lib/MainSwitch.hpp"
#include "../core-lib/Memory.hpp"
#include "../core-lib/UnitDisplay.hpp"
#include "../core-lib/Valve.hpp"

enum KeypadButton : uint8_t {
	Cancel,
	Up,
	Down,
	Confirm,
	NoBtn
};

struct PageController {
	explicit PageController(Keypad& myKeypad, UnitDisplay& myDisplay, Clock& myClock, Valve* myEtv[], MainSwitch& myMainSwitch, Memory& myMemory, AutoCycle& autoCycle);
	Keypad& keypad;
	UnitDisplay& display;
	Clock& clock;
	Valve** etv;
	MainSwitch& mainSwitch;
	Memory& memory;
	AutoCycle& autoCycle;
	bool timeToEdit;
	uint8_t etvNum;
	KeypadButton keypadButton() const;

protected:
};

#endif
