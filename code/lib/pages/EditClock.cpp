#ifndef EDIT_CLOCK_PAGE_CPP
#define EDIT_CLOCK_PAGE_CPP

#include "Page.cpp"
#include "PageController.cpp"

class EditClock: public Page {
private:
    MyTime newTime;
    MyTime oldTime;
    int editPhase = 1;

public:
    EditClock(PageController* controller): Page(controller) {
        this->controller = controller;
        editPhase = 1;
        oldTime = controller->clockGetTime();
        newTime = oldTime;
    }
    PageNum exec() {

        KeypadButton key = controller->keypad();

        if(key != NoBtn) redraw = true;

        switch(key) {
            case Cancel:
                return Stay;

            case Down:
                switch(editPhase) {
                    case 1:
                        newTime.dow = (newTime.dow > Monday) ? newTime.dow-1 : Sunday;
                        break;
                    case 2:
                        newTime.hour = (newTime.hour > 0) ? newTime.hour-1 : 23;
                        break;
                    case 3:
                        newTime.min = (newTime.min > 0) ? newTime.min-1 : 59;
                        break;
                    case 4:
                        newTime.date = (newTime.date > 1) ? newTime.date-1 : 31;
                        break;
                    case 5:
                        newTime.mon = (newTime.mon > 1) ? newTime.mon-1 : 12;
                        break;
                    case 6:
                        newTime.year = (newTime.year > 2021) ? newTime.year-1 : 2021;
                        break;
                }
                return Stay;

            case Up:
                switch(editPhase) {
                    case 1:
                        newTime.dow = (newTime.dow < Sunday) ? newTime.dow+1 : Monday;
                        break;
                    case 2:
                        newTime.hour = (newTime.hour < 23) ? newTime.hour+1 : 0;
                        break;
                    case 3:
                        newTime.min = (newTime.min < 59) ? newTime.min+1 : 0;
                        break;
                    case 4:
                        newTime.date = (newTime.date < 31) ? newTime.date+1 : 1;
                        break;
                    case 5:
                        newTime.mon = (newTime.mon < 12) ? newTime.mon+1 : 1;
                        break;
                    case 6:
                        newTime.year ++;
                        break;
                }
                return Stay;

            case Confirm:
                editPhase++;
                if(editPhase > 6) {
                    controller->clockSetTime(newTime);
                    return HomePage;
                }
                else return Stay;

            default:
                return Stay;
        }

    }
    void show() {
        if(redraw) {
            controller->displayPrint(newTime);
            redraw = false;
        }
    }

protected:

};

#endif
