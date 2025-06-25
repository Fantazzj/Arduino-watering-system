#include "Settings4.hpp"

Settings4::Settings4(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
}

PageNum Settings4::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;
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
	if(redraw) {
		controller.display.printSimpleText(DISPLAY_TEXT);
		redraw = false;
	}
}
