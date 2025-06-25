#include "Settings1.hpp"

Settings1::Settings1(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
}

PageNum Settings1::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;
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
	if(redraw) {
		controller.display.printSimpleText(DISPLAY_TEXT);
		redraw = false;
	}
}
