#include "Settings6.hpp"

Settings6::Settings6(PageController& controller) :
	Page(controller) {
	_controller.display.noBlink();
}

PageNum Settings6::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;
	switch(key) {
		case Cancel:
			return HomePage;
		case Down:
			return SettingsPage5;
		case Up:
			return SettingsPage1;
		case Confirm:
			return EditEtvDaysPage;
		default:
			return Stay;
	}
}

void Settings6::show() {
	if(_redraw) {
		_controller.display.printSimpleText(displayText);
		_redraw = false;
	}
}
