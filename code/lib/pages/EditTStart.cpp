#include "EditTStart.hpp"

EditTStart::EditTStart(PageController& controller) :
	Page(controller) {
	newTime = controller.autoCycle.tStart;
	editPhase = 1;
}

PageNum EditTStart::exec() {
	const KeypadButton key = controller.keypadButton();

	if(key != NoBtn) redraw = true;

	switch(key) {
		case Cancel:
			editPhase = 1;
			return SettingsPage3;

		case Down:
			switch(editPhase) {
				case 1:
					newTime.hour = (newTime.hour > 0) ? newTime.hour - 1 : 23;
					break;
				case 2:
					newTime.min = (newTime.min > 0) ? newTime.min - 5 : 55;
					break;
				default:;
			}
			return Stay;

		case Up:
			switch(editPhase) {
				case 1:
					newTime.hour = (newTime.hour < 23) ? newTime.hour + 1 : 0;
					break;
				case 2:
					newTime.min = (newTime.min < 55) ? newTime.min + 5 : 0;
					break;
				default:;
			}
			return Stay;

		case Confirm:
			editPhase++;
			if(editPhase == 3) {
				editPhase = 1;
				controller.autoCycle.tStart = newTime;
#ifdef DEBUG
				controller.debugger.print("Watering start time set to: ");
				controller.debugger.println(newTime);
#endif
				controller.autoCycle.updateTReset();
				controller.memory.saveStartTime(newTime);
				return HomePage;
			}
			return Stay;

		default:
			return Stay;
	}
}

void EditTStart::show() {
	if(redraw) {
		char text[22] = "Orario di avvio";
		text[15] = ' ';
		text[16] = newTime.hour / 10 + '0';
		text[17] = newTime.hour % 10 + '0';
		text[18] = ':';
		text[19] = newTime.min / 10 + '0';
		text[20] = newTime.min % 10 + '0';
		text[21] = '\0';
		controller.display.printSimpleText(text);
		if(editPhase == 2) controller.display.blinkAt(4, 1);
		else controller.display.blinkAt(1, 1);
		redraw = false;
	}
}
