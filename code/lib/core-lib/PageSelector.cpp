#include "PageSelector.hpp"

PageSelector::PageSelector(Keypad& myKeypad, UnitDisplay& myDisplay, Clock& myClock, ValveGroupN& myEtv, MainSwitch& _myMainSwitch, Memory& myMemory, Timer& myTimer, Debugger& myDebugger, AutoCycle& autoCycle) :
	controller(myKeypad, myDisplay, myClock, myEtv, _myMainSwitch, myMemory, myTimer, myDebugger, autoCycle) {
	activePage = nullptr;
}

void PageSelector::begin() {
	activePage = new Home(controller);

	backlightTurnOnTime = controller.clock.getDateTime().time;
}

void PageSelector::exec() {
	newPage = activePage->exec();
	if(newPage != Stay)
		delete activePage;
	switch(newPage) {
		case Stay:
			break;
		case HomePage:
			activePage = new Home(controller);
			break;
		case SettingsPage1:
			activePage = new Settings1(controller);
			break;
		case EditClockPage:
			activePage = new EditClock(controller);
			break;
		case SettingsPage2:
			activePage = new Settings2(controller);
			break;
		case EditEtvTimePage:
			activePage = new EditEtvTime(controller);
			break;
		case SettingsPage3:
			activePage = new Settings3(controller);
			break;
		case EditTStartPage:
			activePage = new EditTStart(controller);
			break;
		case SettingsPage4:
			activePage = new Settings4(controller);
			break;
		case ManualEtvPage:
			activePage = new ManualEtv(controller);
			break;
		case SettingsPage5:
			activePage = new Settings5(controller);
			break;
		case EditSRWateredPage:
			activePage = new EditSRWatered(controller);
			break;
		case SettingsPage6:
			activePage = new Settings6(controller);
			break;
		case EditEtvDaysPage:
			activePage = new EditEtvDays(controller);
			break;
	}
}

void PageSelector::show() {
	if(controller.keypad.generalPressed()) {
		controller.display.setBacklight(true);
		backlightTurnOnTime = controller.clock.getDateTime().time;
	} else if(secToMin(controller.clock.getDateTime().time - backlightTurnOnTime) >= DISPLAY_BACKLIGHT_MIN_ON) {
		controller.display.setBacklight(false);
	}

	if(controller.display.getBacklight())
		activePage->show();
}
