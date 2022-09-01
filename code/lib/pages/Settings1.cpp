#ifndef SETTINGS1_CPP
#define SETTINGS1_CPP

#include "Page.cpp"

class Settings1: public Page {
private:

public:
    Settings1(PageController* controller): Page(controller) {
        controller->displayHideCursor();
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;
        switch(key) {
            case Cancel:
                return HomePage;
            case Down:
                return SettingsPage6;
            case Up:
                return SettingsPage2;
            case Confirm:
                    return EditClockPage;
            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            controller->displayPrint("Cambia data e ora");
            redraw = false;
        }
    }

protected:

};

#endif
