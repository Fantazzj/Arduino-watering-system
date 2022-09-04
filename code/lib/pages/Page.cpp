#ifndef PAGE_CPP
#define PAGE_CPP

#include "PageController.cpp"

enum PageNum: int8_t{
    Stay = 0,
    HomePage,
    SettingsPage1,
    EditClockPage,
    SettingsPage2,
    EditEtvTimePage,
    SettingsPage3,
    ManualEtvPage,
    SettingsPage4,
    EditSRWateredPage,
    SettingsPage5,
    EditTStartPage,
    SettingsPage6,
    EditEtvDaysPage
};

/*
#define PageNum int
#define Stay 0
#define HomePage 1
#define SettingsPage1 2
#define EditClockPage 3
#define SettingsPage2 4
#define EditEtvTimePage 5
#define SettingsPage3 6
#define ManualEtvPage 7
#define SettingsPage4 8
#define EditSRWateredPage 9
#define SettingsPage5 10
#define EditTStartPage 11
#define SettingsPage6 12
#define EditEtvDaysPage 13
*/

class Page {
private:

public:
    Page(PageController* controller) {
        this->controller = controller;
    }
    virtual PageNum exec() { return Stay; }
    virtual void show() {
        controller->displayPrint("INTERFACCIA");
    }

protected:
    PageController* controller;
    bool redraw = true;

};

#endif
