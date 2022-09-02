#ifndef HOME_CPP
#define HOME_CPP

#include "Page.cpp"
#include "PageController.cpp"

class Home: public Page {
private:
    MyTime newTime;
    MyTime oldTime;

public:
    Home(PageController* controller): Page(controller) {
        controller->displayHideCursor();
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();

        if(key != NoBtn) redraw = true;

        newTime = controller->clockGetTime();
        if(MyTime::isDifferent(oldTime,newTime)) redraw = true;

        if(key == Confirm) return SettingsPage1;
        else return Stay;
    }

    void show() {
        if(redraw) {
            controller->displayPrint(newTime);
            //controller->displayPrint("HOMEPAGE");
            if(controller->getEtvOn() != 0) {
                controller->displayPrint("Etv", 11, 1);
                controller->displayPrint(controller->getEtvOn(), 14, 1);
            }
            else {
                if(controller->autoCycleGetWatered()) controller->displayCheck(true);
                else controller->displayCheck(false);
                /*
                 if(moisture) controller->displayDrop(true);
                 else controller->displayDrop(false);
                */
                if(newTime.year < 2022) controller->displayClock(true);
                else controller->displayClock(false);
            }
            redraw = false;
        }
        oldTime = newTime;
    }

protected:

};

#endif