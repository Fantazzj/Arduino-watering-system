#include "EditClock.hpp"

EditClock::EditClock(PageController& controller) :
	Page(controller) {
	editPhase = 1;
	newTime = controller.clock.getDateTime();
}

PageNum EditClock::exec() {
	const KeypadButton key = controller.keypadButton();

	if(key != NoBtn) redraw = true;

	switch(key) {
		case Cancel:
			editPhase--;
			if(editPhase <= 0) return SettingsPage1;
			return Stay;

		case Down:
			switch(editPhase) {
				case 1:
					newTime.date.dow = (newTime.date.dow > Sunday) ? newTime.date.dow - 1u : Saturday;
					break;
				case 2:
					newTime.time.hour = (newTime.time.hour > 0) ? newTime.time.hour - 1u : 23u;
					break;
				case 3:
					newTime.time.min = (newTime.time.min > 0) ? newTime.time.min - 1u : 59u;
					break;
				case 4:
					newTime.date.day = (newTime.date.day > 1) ? newTime.date.day - 1u : 31u;
					break;
				case 5:
					newTime.date.mon = (newTime.date.mon > 1) ? newTime.date.mon - 1u : 12u;
					break;
				case 6:
					newTime.date.year = (newTime.date.year > 2021) ? newTime.date.year - 1u : 2021u;
					break;
				default:;
			}
			return Stay;

		case Up:
			switch(editPhase) {
				case 1:
					newTime.date.dow = (newTime.date.dow < Saturday) ? newTime.date.dow + 1 : Sunday;
					break;
				case 2:
					newTime.time.hour = (newTime.time.hour < 23) ? newTime.time.hour + 1 : 0;
					break;
				case 3:
					newTime.time.min = (newTime.time.min < 59) ? newTime.time.min + 1 : 0;
					break;
				case 4:
					newTime.date.day = (newTime.date.day < 31) ? newTime.date.day + 1 : 1;
					break;
				case 5:
					newTime.date.mon = (newTime.date.mon < 12) ? newTime.date.mon + 1 : 1;
					break;
				case 6:
					newTime.date.year++;
					break;
				default:;
			}
			return Stay;

		case Confirm:
			editPhase++;
			if(editPhase > 6) {
				controller.clock.setDateTime(newTime);
#ifdef DEBUG
				controller.debugger.print("Date and Time updated: ");
				controller.debugger.println(newTime);
#endif
				controller.timeToEdit = false;
				return HomePage;
			}
			return Stay;

		default:
			return Stay;
	}
}

void EditClock::show() {
	if(redraw) {
		controller.display.showClock(newTime);
		redraw = false;

		switch(editPhase) {
			case 1:
				controller.display.blinkAt(0, 0);
				break;
			case 2:
				controller.display.blinkAt(12, 0);
				break;
			case 3:
				controller.display.blinkAt(15, 0);
				break;
			case 4:
				controller.display.blinkAt(1, 1);
				break;
			case 5:
				controller.display.blinkAt(4, 1);
				break;
			case 6:
				controller.display.blinkAt(9, 1);
				break;
			default:;
		}
	}
}
