#ifndef SETTINGS5_CPP
#define SETTINGS5_CPP

#include "Page.cpp"

class Settings5: public Page {
private:

public:
    Settings5(PageController* controller): Page(controller) {
        _controller->displayHideCursor();
    }

    PageNum exec() {
        KeypadButton key = _controller->keypad();
        if(key != NoBtn) _redraw = true;
        switch(key) {
            case Cancel:
                return HomePage;
            case Down:
                return SettingsPage4;
            case Up:
                return SettingsPage6;
            case Confirm:
                return EditSRWateredPage;
            default:
                return Stay;
        }
    }

    void show() {
        if(_redraw) {
            _controller->displayPrint("Imposta memoria inn.");
            _redraw = false;
        }
    }

protected:

};

#endif
