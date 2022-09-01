#ifndef SETTINGS4_CPP
#define SETTINGS4_CPP

#include "Page.cpp"

class Settings4: public Page {
private:

public:
    Settings4(PageController* controller): Page(controller) {
        controller->displayHideCursor();
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;
        switch(key) {
            case Cancel:
                return HomePage;
            case Down:
                return SettingsPage3;
            case Up:
                return SettingsPage5;
            case Confirm:
                return ManualEtvPage;
            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            controller->displayPrint("Impostazione manuale");
            redraw = false;
        }
    }

protected:

};

#endif
