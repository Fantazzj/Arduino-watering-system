#ifndef PAGE_CONTROLLER_HPP
#define PAGE_CONTROLLER_HPP

#include "../core-lib/AutoCycle.hpp"
#include "../core-lib/Clock.hpp"
#include "../core-lib/Keypad.hpp"
#include "../core-lib/MainSwitch.hpp"
#include "../core-lib/Memory.hpp"
#include "../core-lib/Timer.hpp"
#include "../core-lib/UnitDisplay.hpp"
#include "../core-lib/ValveGroup.hpp"

enum KeypadButton : uint8_t {
	Cancel,
	Up,
	Down,
	Confirm,
	NoBtn
};

struct PageController {
	explicit PageController(Keypad& myKeypad, UnitDisplay& myDisplay, Clock& myClock, ValveGroupN& myEtv, MainSwitch& myMainSwitch, Memory& myMemory, Timer& myTimer, Debugger& myDebugger, AutoCycle& autoCycle);
	Keypad& keypad;
	UnitDisplay& display;
	Clock& clock;
	ValveGroupN& etv;
	MainSwitch& mainSwitch;
	Memory& memory;
	Timer& timer;
	Debugger& debugger;
	AutoCycle& autoCycle;
	bool timeToEdit;
	KeypadButton keypadButton() const;

protected:
};

#endif
