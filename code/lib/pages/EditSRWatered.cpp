#ifndef EDIT_SR_WATERED_CPP
#define EDIT_SR_WATERED_CPP

#include "Page.cpp"

class EditSRWatered: public Page {
private:
    bool watered = false;

public:
    EditSRWatered(PageController* controller): Page(controller) {
        watered = controller->autoCycleGetWatered();
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();

        if(key != NoBtn) redraw = true;

        switch(key) {
            case Cancel:
                return SettingsPage5;

            case Confirm:
                controller->autoCycleSetWatered(!watered);
                return HomePage;

            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            if(!watered) controller->displayPrint("Imposta gia' innaffiato");
            else controller->displayPrint("Imposta da innaffiare");
            controller->displayShowCursor(15,1);
            redraw = false;
        }
    }

protected:

};

#endif
