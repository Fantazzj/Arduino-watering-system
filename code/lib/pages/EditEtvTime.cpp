#ifndef EDIT_ETV_TIME_CPP
#define EDIT_ETV_TIME_CPP

#include "Page.cpp"

class EditEtvTime : public Page{
private:
    int etvEdit = 1;
    int timeEdit = controller->getEtvMinOn(1);

public:
    EditEtvTime(PageController *controller) : Page(controller) {
        etvEdit = 1;
        timeEdit = controller->getEtvMinOn(1);
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;

        switch(key) {
            case Cancel:
                if(etvEdit >= 2) {
                    etvEdit--;
                    timeEdit = controller->getEtvMinOn(etvEdit);
                    return Stay;
                }
                else {
                    etvEdit = 1;
                    timeEdit = 0;
                    return SettingsPage2;
                }

            case Down:
                if(timeEdit <= 10) timeEdit--;
                else timeEdit -= 5;
                if(timeEdit <= 0) timeEdit=0;
                return Stay;

            case Up:
                if(timeEdit < 10) timeEdit++;
                else timeEdit+=5;
                return Stay;

            case Confirm:
                controller->setEtvMinOn(etvEdit++, timeEdit);
                timeEdit = controller->getEtvMinOn(etvEdit);
                if(etvEdit > controller->etvNum)
                    return HomePage;
                else return Stay;
        }

    }

    void show() {
        if(redraw) {
            controller->displayPrint("Etv", etvEdit, "per", timeEdit, "minuti");
            controller->displayShowCursor(10, 0);
            redraw = false;
        }
    }

protected:

};

#endif
