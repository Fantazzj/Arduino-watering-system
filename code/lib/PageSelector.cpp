#ifndef PAGE_SELECTOR_CPP
#define PAGE_SELECTOR_CPP

#include "AutoCycle.cpp"

#include "pages/Home.hpp"
#include "pages/Page.hpp"
#include "pages/PageController.hpp"

#include "pages/EditClock.hpp"
#include "pages/Settings1.hpp"

#include "pages/EditEtvTime.hpp"
#include "pages/Settings2.hpp"

#include "pages/EditTStart.hpp"
#include "pages/Settings3.hpp"

#include "pages/ManualEtv.hpp"
#include "pages/Settings4.hpp"

#include "pages/EditSRWatered.hpp"
#include "pages/Settings5.hpp"

#include "pages/EditEtvDays.hpp"
#include "pages/Settings6.hpp"

class PageSelector {
private:
	PageController* controller;

	Page* activePage;

	PageNum newPage = Stay;

	MyTime lightTime;

public:
	PageSelector(Keypad* myKeypad, UnitDisplay* myDisplay, Clock* myClock, Valve* myEtv[], AutoCycle* autoCycle) {
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
