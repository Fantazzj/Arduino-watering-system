#include "Settings2.hpp"

Settings2::Settings2(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
}

PageNum Settings2::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;
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
	if(redraw) {
		controller.display.printSimpleText(DISPLAY_TEXT);
		redraw = false;
	}
}
