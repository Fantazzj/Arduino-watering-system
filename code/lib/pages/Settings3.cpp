#include "Settings3.hpp"

Settings3::Settings3(PageController* controller) :
	Page(controller) {
	_controller->display.noBlink();
}

PageNum Settings3::exec() {
	KeypadButton key = _controller->keypadButton();
	if(key != NoBtn) _redraw = true;
	switch(key) {
		case Cancel:
			return HomePage;
		case Down:
			return SettingsPage2;
		case Up:
			return SettingsPage4;
		case Confirm:
			return EditTStartPage;
		default:
			return Stay;
	}
}

void Settings3::show() {
	if(_redraw) {
		_controller->display.printSimpleText((char*) "Cambia orario di avvio");
		_redraw = false;
	}
}
