#include "Settings4.hpp"

Settings4::Settings4(PageController& controller) :
	Page(controller) {
	_controller.display.noBlink();
}

PageNum Settings4::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;
	switch(key) {
		case Cancel:
			return HomePage;
		case Down:
			return SettingsPage3;
		case Up:
			return SettingsPage5;
		case Confirm:
			return ManualEtvPage;
		default:
			return Stay;
	}
}

void Settings4::show() {
	if(_redraw) {
		_controller.display.printSimpleText("Impostazione manuale");
		_redraw = false;
	}
}
