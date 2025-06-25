#include "Settings5.hpp"

Settings5::Settings5(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
}

PageNum Settings5::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;
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
	if(redraw) {
		controller.display.printSimpleText(DISPLAY_TEXT);
		redraw = false;
	}
}
