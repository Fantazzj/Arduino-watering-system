#include "Home.hpp"

Home::Home(PageController* controller) :
	Page(controller) {
	_controller->displayHideCursor();
	_newTime = _controller->clockGetTime();
}

PageNum Home::exec() {
	KeypadButton key = _controller->keypad();

	if(key != NoBtn) _redraw = true;

	_newTime = _controller->clockGetTime();
	if(_oldTime != _newTime) _redraw = true;

	if(key == Confirm) return SettingsPage1;
	else return Stay;
}

void Home::show() {
	if(_redraw) {
		_controller->displayPrint(_newTime);
		//_controller->displayPrint("HOMEPAGE");
		if(_controller->getEtvOn() != 0) {
			_controller->displayPrint((char*) "Etv", 11, 1);
			_controller->displayPrint(_controller->getEtvOn(), 14, 1);
		} else {
			if(_controller->autoCycleGetWatered()) _controller->displayCheck(true);
			else _controller->displayCheck(false);
			/*
            	if(moisture) _controller->displayDrop(true);
            	else _controller->displayDrop(false);
			*/
			if(_newTime.date.year < 2022 or _controller->getTimeToEdit()) _controller->displayClock(true);
			else _controller->displayClock(false);
		}
		_redraw = false;
	}
	_oldTime = _newTime;
}
