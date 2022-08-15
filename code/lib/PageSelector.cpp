#ifndef PAGE_SELECTOR_CPP
#define PAGE_SELECTOR_CPP

#include "pages/PageController.cpp"
#include "pages/Page.cpp"
#include "pages/Home.cpp"
#include "pages/Settings1.cpp"
#include "pages/Settings2.cpp"
#include "pages/EditEtvTime.cpp"
#include "pages/Settings3.cpp"
#include "pages/ManualEtv.cpp"
#include "pages/Settings4.cpp"
#include "pages/Settings5.cpp"
#include "pages/Settings6.cpp"
#include "pages/EditEtvDays.cpp"

class PageSelector {
private:
    PageController* controller;

    Page* activePage;

    Home* home;
    Settings1* settings1;
    Settings2* settings2;
    EditEtvTime* editEtvTime;
    Settings3* settings3;
    ManualEtv* manualEtv;
    Settings4* settings4;
    Settings5* settings5;
    Settings6* settings6;
    EditEtvDays* editEtvDays;

    PageNum newPage = Stay;
    PageNum oldPage = newPage;

public:
    PageSelector(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[]) {

        this->controller = new PageController(myKeypad, myDebugger, myDisplay, myClock, myEtv);

        home = new Home(controller);
        settings1 = new Settings1(controller);
        manualEtv = new ManualEtv(controller);
        settings2 = new Settings2(controller);
        editEtvTime = new EditEtvTime(controller);
        settings3 = new Settings3(controller);
        settings4 = new Settings4(controller);
        settings5 = new Settings5(controller);
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
            case SettingsPage2:
                activePage = settings2;
                break;
            case EditEtvTimePage:
                activePage = editEtvTime;
                break;
            case SettingsPage3:
                activePage = settings3;
                break;
            case ManualEtvPage:
                activePage = manualEtv;
                break;
            case SettingsPage4:
                activePage = settings4;
                break;
            case SettingsPage5:
                activePage = settings5;
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
