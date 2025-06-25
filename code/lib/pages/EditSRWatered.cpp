#include "EditSRWatered.hpp"

EditSRWatered::EditSRWatered(PageController& controller) :
	Page(controller) {
	watered = controller.autoCycle.watered;
}

PageNum EditSRWatered::exec() {
	const KeypadButton key = controller.keypadButton();

	if(key != NoBtn) redraw = true;

	switch(key) {
		case Cancel:
			return SettingsPage5;

		case Confirm:
			controller.autoCycle.watered = !watered;
#ifdef DEBUG
			if(watered)
				controller.debugger.println("Reset watered state");
			else
				controller.debugger.println("Set watered state");
#endif
			return HomePage;

		default:
			return Stay;
	}
}

void EditSRWatered::show() {
	if(redraw) {
		if(!watered) controller.display.printSimpleText("Imposta gia' innaffiato");
		else controller.display.printSimpleText("Imposta da innaffiare");
		controller.display.blinkAt(15, 1);
		redraw = false;
	}
}
