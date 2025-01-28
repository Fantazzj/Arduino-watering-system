#include "Home.hpp"

Home::Home(PageController& controller) :
	Page(controller) {
	_controller.display.noBlink();
	_newTime = _controller.clock.getDateTime();
}

PageNum Home::exec() {
	KeypadButton key = _controller.keypadButton();

	if(key != NoBtn) _redraw = true;

	_newTime = _controller.clock.getDateTime();
	if(_oldTime.time.min != _newTime.time.min) _redraw = true;

	if(_controller.autoCycle.etvOn != oldEtvOn) _redraw = true;
	oldEtvOn = _controller.autoCycle.etvOn;

	if(key == Confirm) return SettingsPage1;
	else return Stay;
}

void Home::show() {
	if(_redraw) {
		_controller.display.showClock(_newTime);
		//_controller.displayPrint("HOMEPAGE");
		if(_controller.autoCycle.etvOn != -1) {
			_controller.display.printIn("Etv", 11, 1);
			_controller.display.printIn(_controller.autoCycle.etvOn+1, 14, 1);
		} else {
			if(_controller.autoCycle.watered) _controller.display.checkSym(true);
			else _controller.display.checkSym(false);
			/*
            	if(moisture) _controller.display.dropSym(true);
            	else _controller.display.dropSym(false);
			*/
			if(_newTime.date.year < 2022 || _controller.timeToEdit) _controller.display.clockSym(true);
			else _controller.display.clockSym(false);
		}
		_redraw = false;
	}
	_oldTime = _newTime;
}
