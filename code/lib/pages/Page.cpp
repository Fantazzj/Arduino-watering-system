#ifndef PAGE_CPP
#define PAGE_CPP

#include "PageController.cpp"

enum PageNum: int{
    Stay,
    HomePage,
    SettingsPage1,
    EditClockPage,
    SettingsPage2,
    EditEtvTimePage,
    SettingsPage3,
    ManualEtvPage,
    SettingsPage4,
    SettingsPage5,
    SettingsPage6,
    EditEtvDaysPage
};

class Page {
private:

public:
    Page(PageController* controller) {
        this->controller = controller;
    }
    virtual PageNum exec() { return Stay;}
    virtual void show() {
        controller->displayPrint("INTERFACCIA");
    }

protected:
    PageController* controller;
    bool redraw = true;

};

#endif
