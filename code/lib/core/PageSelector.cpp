#include "PageSelector.hpp"

PageSelector::PageSelector(Keypad* myKeypad, UnitDisplay* myDisplay, Clock* myClock, Valve* myEtv[], AutoCycle* autoCycle) {
	this->controller = new PageController(myKeypad, myDisplay, myClock, myEtv, autoCycle);

	activePage = new Home(controller);

	lightTime = controller->clockGetTime();
}

void PageSelector::exec() {
	newPage = activePage->exec();
	switch(newPage) {
		case Stay:
			break;
		case HomePage:
			delete activePage;
			activePage = new Home(controller);
			break;
		case SettingsPage1:
			delete activePage;
			activePage = new Settings1(controller);
			break;
		case EditClockPage:
			delete activePage;
			activePage = new EditClock(controller);
			break;
		case SettingsPage2:
			delete activePage;
			activePage = new Settings2(controller);
			break;
		case EditEtvTimePage:
			delete activePage;
			activePage = new EditEtvTime(controller);
			break;
		case SettingsPage3:
			delete activePage;
			activePage = new Settings3(controller);
			break;
		case EditTStartPage:
			delete activePage;
			activePage = new EditTStart(controller);
			break;
		case SettingsPage4:
			delete activePage;
			activePage = new Settings4(controller);
			break;
		case ManualEtvPage:
			delete activePage;
			activePage = new ManualEtv(controller);
			break;
		case SettingsPage5:
			delete activePage;
			activePage = new Settings5(controller);
			break;
		case EditSRWateredPage:
			delete activePage;
			activePage = new EditSRWatered(controller);
			break;
		case SettingsPage6:
			delete activePage;
			activePage = new Settings6(controller);
			break;
		case EditEtvDaysPage:
			delete activePage;
			activePage = new EditEtvDays(controller);
			break;
	}
}

void PageSelector::show() {
	activePage->show();

	if(controller->keypadGeneral()) {
		controller->displaySetBacklight(true);
		lightTime = controller->clockGetTime();
	} else if(MyTime::elapsedMin(lightTime, controller->clockGetTime()) >= 2) {
		controller->displaySetBacklight(false);
	}
}
