#ifndef EDIT_ETV_DAYS_CPP
#define EDIT_ETV_DAYS_CPP

#include "Page.cpp"

class EditEtvDays : public Page{
private:
    int etvEdit = 1;
    int daysEdit = controller->getEtvDays(1);

public:
    EditEtvDays(PageController *controller) : Page(controller) {}

    PageNum exec() {
        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;

        switch(key) {
            case Cancel:
                if(etvEdit >= 2) {
                    etvEdit--;
                    daysEdit = controller->getEtvDays(etvEdit);
                    return Stay;
                }
                else {
                    etvEdit = 1;
                    daysEdit = 0;
                    return SettingsPage6;
                }

            case Down:
                if(daysEdit <= 10) daysEdit--;
                else daysEdit -= 5;
                if(daysEdit <= 0) daysEdit=0;
                return Stay;

            case Up:
                if(daysEdit < 10) daysEdit++;
                else daysEdit+=5;
                return Stay;

            case Confirm:
                controller->setEtvDays(etvEdit++, daysEdit);
                daysEdit = controller->getEtvDays(etvEdit);
                if(etvEdit > controller->etvNum) {
                    etvEdit = 1;
                    daysEdit = controller->getEtvDays(1);
                    return HomePage;
                }
                else return Stay;
        }

    }

    void show() {
        if(redraw) {
            controller->displayPrint("Etv", etvEdit, "ogni", daysEdit, "giorni");
            redraw = false;
        }
    }

protected:

};

#endif
