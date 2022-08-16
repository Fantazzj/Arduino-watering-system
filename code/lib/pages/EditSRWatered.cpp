#ifndef EDIT_SR_WATERED_CPP
#define EDIT_SR_WATERED_CPP

#include "Page.cpp"

class EditSRWatered: public Page {
private:
    bool watered = false;
    int i;

public:
    EditSRWatered(PageController* controller): Page(controller) {}

    PageNum exec() {
        KeypadButton key = controller->keypad();

        if(key != NoBtn) redraw = true;

        for(; i<1; i++) {
            watered = controller->autoCycleGetWatered();
        }

        switch(key) {
            case Cancel:
                return SettingsPage5;

            case Confirm:
                controller->autoCycleSetWatered(!watered);
                i=0;
                return HomePage;

            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            if(!watered) controller->displayPrint("Imposta da innaffiare");
            else controller->displayPrint("Imposta gia' innaffiato");
            redraw = false;
        }
    }

protected:

};

#endif
