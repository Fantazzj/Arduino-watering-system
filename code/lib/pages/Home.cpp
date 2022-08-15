#ifndef HOME_CPP
#define HOME_CPP

#include "Page.cpp"
#include "PageController.cpp"

class Home: public Page {
private:
    MyTime newTime;
    MyTime oldTime;

public:
    Home(PageController* controller): Page(controller) {}

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
            redraw = false;
        }
        oldTime = newTime;
    }

protected:

};

#endif