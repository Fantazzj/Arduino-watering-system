#include "Home.hpp"

Home::Home(PageController& controller) :
	Page(controller) {
	controller.display.noBlink();
	newTime = controller.clock.getDateTime();
}

PageNum Home::exec() {
	const KeypadButton key = controller.keypadButton();

	if(key != NoBtn) redraw = true;

	newTime = controller.clock.getDateTime();
	if(_oldTime.time.min != newTime.time.min) redraw = true;

	if(controller.autoCycle.etvOn != oldEtvOn) redraw = true;
	oldEtvOn = controller.autoCycle.etvOn;

	if(key == Confirm) return SettingsPage1;

	return Stay;
}

void Home::show() {
	if(redraw) {
		controller.display.showClock(newTime);
		if(controller.autoCycle.etvOn != -1) {
			controller.display.printIn("Etv", 11, 1);
			controller.display.printIn(controller.autoCycle.etvOn + 1, 14, 1);
		} else {
			controller.display.checkSym(controller.autoCycle.watered);
			controller.display.dropSym(controller.autoCycle.moist);
			controller.display.clockSym(newTime.date.year < 2022 || controller.timeToEdit);
		}
		redraw = false;
	}
	_oldTime = newTime;
}
