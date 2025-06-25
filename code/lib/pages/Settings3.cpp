#include "Settings3.hpp"

Settings3::Settings3(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
}

PageNum Settings3::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;
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
	if(redraw) {
		controller.display.printSimpleText(DISPLAY_TEXT);
		redraw = false;
	}
}
