#include "EditEtvTime.hpp"

EditEtvTime::EditEtvTime(PageController& controller) :
	Page(controller) {
	etvEdit = 0;
	timeEdit = controller.etv.getMinOn(0);
}

PageNum EditEtvTime::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;

	switch(key) {
		case Cancel: {
			if(etvEdit > 0) {
				etvEdit--;
				timeEdit = controller.etv.getMinOn(etvEdit);
				return Stay;
			}
			etvEdit = 0;
			timeEdit = 0;
			return SettingsPage2;
		}

		case Down:
			if(timeEdit <= 0) {
				timeEdit = 0;
				return Stay;
			}
			if(timeEdit <= 10) timeEdit--;
			else timeEdit -= 5;
			return Stay;

		case Up:
			if(timeEdit >= 120) {
				timeEdit = 120;
				return Stay;
			}
			if(timeEdit < 10) timeEdit++;
			else timeEdit += 5;
			return Stay;

		case Confirm:
			controller.etv.setMinOn(etvEdit, timeEdit);
			controller.memory.saveEtvMinOn(etvEdit, timeEdit);
			etvEdit++;
			timeEdit = controller.etv.getMinOn(etvEdit);
			if(etvEdit >= VALVE_NUM) {
				controller.autoCycle.updateTReset();
#ifdef DEBUG
				controller.debugger.print("New etv minOn: [ ");
				for(uint8_t e = 0; e < VALVE_NUM; e++) {
					controller.debugger.print(controller.etv.getMinOn(e));
					controller.debugger.print(' ');
				}
				controller.debugger.println(']');
#endif

				return HomePage;
			}
			return Stay;

		default:
			return Stay;
	}
}

void EditEtvTime::show() {
	if(redraw) {
		controller.display.printData("Etv", etvEdit + 1, "per", timeEdit, "minuti");
		const int8_t numDigits = 1 + (timeEdit >= 10) + (timeEdit >= 100);
		controller.display.blinkAt(9 + numDigits, 0);
		redraw = false;
	}
}
