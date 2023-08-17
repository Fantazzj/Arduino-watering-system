#include "Settings1.hpp"

Settings1::Settings1(PageController* controller) :
	Page(controller) {
	_controller->displayHideCursor();
}

PageNum Settings1::exec() {
	KeypadButton key = _controller->keypad();
	if(key != NoBtn) _redraw = true;
	switch(key) {
		case Cancel:
			return HomePage;
		case Down:
			return SettingsPage6;
		case Up:
			return SettingsPage2;
		case Confirm:
			return EditClockPage;
		default:
			return Stay;
	}
}

void Settings1::show() {
	if(_redraw) {
		_controller->displayPrint((char*) "Cambia data e ora");
		_redraw = false;
	}
}
