#include "PageController.hpp"

PageController::PageController(Keypad& myKeypad, UnitDisplay& myDisplay, Clock& myClock, ValveGroupN& myEtv, MainSwitch& myMainSwitch, Memory& myMemory, Timer& myTimer, Debugger& myDebugger, AutoCycle& autoCycle) :
	keypad(myKeypad), display(myDisplay), clock(myClock), etv(myEtv), mainSwitch(myMainSwitch), memory(myMemory), timer(myTimer), debugger(myDebugger), autoCycle(autoCycle) {
	timeToEdit = true;
}

KeypadButton PageController::keypadButton() const {
	if(keypad.cancel()) return Cancel;
	if(keypad.down()) return Down;
	if(keypad.up()) return Up;
	if(keypad.confirm()) return Confirm;
	return NoBtn;
}
