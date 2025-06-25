#include "Settings6.hpp"

Settings6::Settings6(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
}

PageNum Settings6::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;
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
	if(redraw) {
		controller.display.printSimpleText(DISPLAY_TEXT);
		redraw = false;
	}
}
