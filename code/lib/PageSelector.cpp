#ifndef PAGE_SELECTOR_CPP
#define PAGE_SELECTOR_CPP

#include "AutoCycle.cpp"

#include "pages/PageController.cpp"
#include "pages/Page.cpp"
#include "pages/Home.cpp"

#include "pages/Settings1.cpp"
#include "pages/EditClock.cpp"

#include "pages/Settings2.cpp"
#include "pages/EditEtvTime.cpp"

#include "pages/Settings3.cpp"


#include "pages/Settings4.cpp"
#include "pages/ManualEtv.cpp"

#include "pages/Settings5.cpp"
#include "pages/EditSRWatered.cpp"

#include "pages/Settings6.cpp"
#include "pages/EditEtvDays.cpp"

class PageSelector {
private:
    PageController* controller;

    Page* activePage;

    Home* home;
    Settings1* settings1;
    EditClock* editClock;

    Settings2* settings2;
    EditEtvTime* editEtvTime;

    Settings3* settings3;


    Settings4* settings4;
    ManualEtv* manualEtv;

    Settings5* settings5;
    EditSRWatered* editSrWatered;

    Settings6* settings6;
    EditEtvDays* editEtvDays;

    PageNum newPage = Stay;
    PageNum oldPage = newPage;

public:
    PageSelector(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[], AutoCycle* autoCycle) {

        this->controller = new PageController(myKeypad, myDebugger, myDisplay, myClock, myEtv, autoCycle);

        home = new Home(controller);

        settings1 = new Settings1(controller);
        editClock = new EditClock(controller);

        settings2 = new Settings2(controller);
        editEtvTime = new EditEtvTime(controller);

        settings3 = new Settings3(controller);


        settings4 = new Settings4(controller);
        manualEtv = new ManualEtv(controller);

        settings5 = new Settings5(controller);
        editSrWatered = new EditSRWatered(controller);

        settings6 = new Settings6(controller);
        editEtvDays = new EditEtvDays(controller);

        activePage = home;

    }

    void exec() {
        newPage = activePage->exec();
        switch(newPage){
            case Stay:
                break;
            case HomePage:
                activePage = home;
                break;
            case SettingsPage1:
                activePage = settings1;
                break;
            case EditClockPage:
                activePage = editClock;
                break;
            case SettingsPage2:
                activePage = settings2;
                break;
            case EditEtvTimePage:
                activePage = editEtvTime;
                break;
            case SettingsPage3:
                activePage = settings3;
                break;
            case EditTStartPage:
                //TODO activePage = ;
                break;
            case SettingsPage4:
                activePage = settings4;
                break;
            case ManualEtvPage:
                activePage = manualEtv;
                break;
            case SettingsPage5:
                activePage = settings5;
                break;
            case EditSRWateredPage:
                activePage = editSrWatered;
                break;
            case SettingsPage6:
                activePage = settings6;
                break;
            case EditEtvDaysPage:
                activePage = editEtvDays;
                break;
        }

        oldPage = newPage;
    }

    void show() {
        activePage->show();
    }

protected:

};

#endif
