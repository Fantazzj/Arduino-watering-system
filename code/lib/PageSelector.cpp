#ifndef PAGE_SELECTOR_CPP
#define PAGE_SELECTOR_CPP

#include "AutoCycle.cpp"

#include "pages/Home.cpp"
#include "pages/Page.cpp"
#include "pages/PageController.cpp"

#include "pages/EditClock.cpp"
#include "pages/Settings1.cpp"

#include "pages/EditEtvTime.cpp"
#include "pages/Settings2.cpp"

#include "pages/EditTStart.cpp"
#include "pages/Settings3.cpp"

#include "pages/ManualEtv.cpp"
#include "pages/Settings4.cpp"

#include "pages/EditSRWatered.cpp"
#include "pages/Settings5.cpp"

#include "pages/EditEtvDays.cpp"
#include "pages/Settings6.cpp"

class PageSelector {
private:
	PageController* controller;

	Page* activePage;

	PageNum newPage = Stay;

	MyTime lightTime;

public:
	PageSelector(Keypad* myKeypad, Display* myDisplay, Clock* myClock, Valve* myEtv[], AutoCycle* autoCycle) {
		this->controller = new PageController(myKeypad, myDisplay, myClock, myEtv, autoCycle);

		activePage = new Home(controller);

		lightTime = controller->clockGetTime();
	}

	void exec() {
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

	void show() {
		activePage->show();

		if(controller->keypadGeneral()) {
			controller->displaySetBacklight(true);
			lightTime = controller->clockGetTime();
		} else if(MyTime::elapsedMin(lightTime, controller->clockGetTime()) >= 2) {
			controller->displaySetBacklight(false);
		}
	}

protected:
};

#endif
