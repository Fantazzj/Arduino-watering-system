#include "Settings5.hpp"

Settings5::Settings5(PageController* controller) :
	Page(controller) {
	_controller->displayHideCursor();
}

PageNum Settings5::exec() {
	KeypadButton key = _controller->keypad();
	if(key != NoBtn) _redraw = true;
	switch(key) {
		case Cancel:
			return HomePage;
		case Down:
			return SettingsPage4;
		case Up:
			return SettingsPage6;
		case Confirm:
			return EditSRWateredPage;
		default:
			return Stay;
	}
}

void Settings5::show() {
	if(_redraw) {
		_controller->displayPrint((char*) "Imposta memoria inn.");
		_redraw = false;
	}
}
