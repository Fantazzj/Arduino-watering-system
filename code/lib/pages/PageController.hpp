#ifndef PAGE_CONTROLLER_HPP
#define PAGE_CONTROLLER_HPP

#include "../core/AutoCycle.hpp"
#include "../core/Clock.hpp"
#include "../core/Keypad.hpp"
#include "../core/MainSwitch.hpp"
#include "../core/Memory.hpp"
#include "../core/Timer.hpp"
#include "../core/UnitDisplay.hpp"
#include "../core/ValveGroup.hpp"

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
