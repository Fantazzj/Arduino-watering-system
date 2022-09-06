#ifndef SETTINGS6_CPP
#define SETTINGS6_CPP

#include "Page.cpp"

class Settings6: public Page {
private:

public:
    Settings6(PageController* controller): Page(controller) {
        _controller->displayHideCursor();
    }

    PageNum exec() {
        KeypadButton key = _controller->keypad();
        if(key != NoBtn) _redraw = true;
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
        if(_redraw) {
            _controller->displayPrint("Imposta giorni");
            _redraw = false;
        }
    }

protected:

};

#endif
