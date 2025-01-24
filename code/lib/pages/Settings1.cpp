#include "Settings1.hpp"

Settings1::Settings1(PageController* controller) :
	Page(controller) {
	_controller->display.noBlink();
}

PageNum Settings1::exec() {
	KeypadButton key = _controller->keypadButton();
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
		_controller->display.printSimpleText((char*) "Cambia data e ora");
		_redraw = false;
	}
}
