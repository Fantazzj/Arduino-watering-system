#ifndef SETTINGS3_CPP
#define SETTINGS3_CPP

#include "Page.cpp"

class Settings3: public Page {
private:

public:
    Settings3(PageController* controller): Page(controller) {}

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;
        switch(key) {
            case Cancel:
                return HomePage;
            case Down:
                return SettingsPage2;
            case Up:
                return SettingsPage4;
            case Confirm:
                return EditTStartPage;
            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            controller->displayPrint("Cambia orario di avvio");
            redraw = false;
        }
    }

protected:

};

#endif
