#ifndef SETTINGS5_CPP
#define SETTINGS5_CPP

#include "Page.cpp"

class Settings5: public Page {
private:

public:
    Settings5(PageController* controller): Page(controller) {}

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;
        switch(key) {
            case Cancel:
                return HomePage;
            case Down:
                return SettingsPage4;
            case Up:
                return SettingsPage6;
            case Confirm:
                return Stay; //TODO add page
            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            controller->displayPrint("Imposta memoria inn.");
            redraw = false;
        }
    }

protected:

};

#endif
