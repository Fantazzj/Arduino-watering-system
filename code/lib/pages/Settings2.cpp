#include "Settings2.hpp"

Settings2::Settings2(PageController* controller) :
	Page(controller) {
	_controller->display->noBlink();
}

PageNum Settings2::exec() {
	KeypadButton key = _controller->keypadButton();
	if(key != NoBtn) _redraw = true;
	switch(key) {
		case Cancel:
			return HomePage;
		case Down:
			return SettingsPage1;
		case Up:
			return SettingsPage3;
		case Confirm:
			return EditEtvTimePage;
		default:
			return Stay;
	}
}

void Settings2::show() {
	if(_redraw) {
		_controller->display->printSimpleText((char*) "Cambia tempo elettrovalvole");
		_redraw = false;
	}
}
