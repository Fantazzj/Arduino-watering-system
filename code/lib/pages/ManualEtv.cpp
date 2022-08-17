#ifndef MANUAL_ETV_CPP
#define MANUAL_ETV_CPP

#include "Page.cpp"
#include "PageController.cpp"

class ManualEtv: public Page {
private:
    int num = 1;

public:
    ManualEtv(PageController* controller): Page(controller) {
        num = 1;
    }

    PageNum exec() {

        KeypadButton key = controller->keypad();
        if(key != NoBtn) redraw = true;

        if(controller->etvOn == 0) {
            if (key == Up) { //TODO convert in switch
                num++;
                if(num > controller->etvNum) num = 1;
            }

            if (key == Down) {
                num--;
                if(num < 1) num = controller->etvNum;
            }

            if (key == Cancel) {
                num = 1;
                return SettingsPage1;
            }

            if (key == Confirm) {
                controller->setEtvState(num, true);
                controller->etvOn = num;
                return HomePage;
            }
        }
        else {
            if (key == Cancel) {
                return SettingsPage1;
            }

            if (key == Confirm) {
                controller->setEtvState(controller->etvOn, false);
                controller->etvOn = 0;
                return HomePage;
            }
        }

        return Stay;

    }

    void show() {
        if(redraw) {
            if (controller->etvOn == 0) controller->displayPrint("Accendi elettrovalvola", num, "");
            else controller->displayPrint("Spegni elettrovalvola", controller->etvOn, "");
            redraw = false;
        }
    }

protected:

};

#endif
