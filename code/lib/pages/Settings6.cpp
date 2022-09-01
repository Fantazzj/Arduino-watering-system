#ifndef SETTINGS6_CPP
#define SETTINGS6_CPP

#include "Page.cpp"

class Settings6: public Page {
private:

public:
    Settings6(PageController* controller): Page(controller) {
        controller->displayHideCursor();
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;
        switch(key) {
            case Cancel:
                return HomePage;
            case Down:
                return SettingsPage5;
            case Up:
                return SettingsPage1;
            case Confirm:
                return EditEtvDaysPage;
            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            controller->displayPrint("Imposta giorni");
            redraw = false;
        }
    }

protected:

};

#endif
