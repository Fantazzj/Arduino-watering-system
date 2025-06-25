#include "EditEtvDays.hpp"

EditEtvDays::EditEtvDays(PageController& controller) :
	Page(controller) {
	etvEdit = 0;
	daysEdit = controller.etv.getDays(0);
}

PageNum EditEtvDays::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;

	switch(key) {
		case Cancel: {
			if(etvEdit > 0) {
				etvEdit--;
				daysEdit = controller.etv.getDays(etvEdit);
				return Stay;
			}
			etvEdit = 0;
			daysEdit = 0;
			return SettingsPage6;
		}

		case Down:
			if(daysEdit <= 0) {
				daysEdit = 0;
				return Stay;
			}
			if(daysEdit <= 10) daysEdit--;
			else daysEdit -= 5;
			return Stay;

		case Up:
			if(daysEdit >= 30) {
				daysEdit = 30;
				return Stay;
			}
			if(daysEdit < 10) daysEdit++;
			else daysEdit += 5;
			return Stay;

		case Confirm:
			controller.etv.setDays(etvEdit, daysEdit);
			controller.memory.saveEtvDays(etvEdit, daysEdit);
			etvEdit++;
			daysEdit = controller.etv.getDays(etvEdit);
			if(etvEdit >= VALVE_NUM) {
#ifdef DEBUG
				controller.debugger.print("New etv days: [ ");
				for(uint8_t e = 0; e < VALVE_NUM; e++) {
					controller.debugger.print(controller.etv.getDays(e));
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

void EditEtvDays::show() {
	if(redraw) {
		controller.display.printData("Etv", etvEdit + 1, "ogni", daysEdit, "giorni");
		const int8_t numDigits = 1 + (daysEdit >= 10);
		controller.display.blinkAt(10 + numDigits, 0);
		redraw = false;
	}
}
