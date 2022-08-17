#ifndef EDIT_T_START_CPP
#define EDIT_T_START_CPP

#include "Page.cpp"

class EditTStart: public Page {
private:
    MyTime newTime;
    int editPhase = 1;

public:
    EditTStart(PageController* controller): Page(controller) {
        newTime = controller->autoCycleGetTStart();
    }

    PageNum exec() {
        KeypadButton key = controller->keypad();

        if(key != NoBtn) redraw = true;

        switch(key) {
            case Cancel:
                editPhase = 1;
                return SettingsPage3;

            case Down:
                switch(editPhase) {
                    case 1:
                        newTime.hour = (newTime.hour > 0) ? newTime.hour-1 : 23;
                        break;
                    case 2:
                        newTime.min = (newTime.min > 0) ? newTime.min-5 : 55;
                        break;
                }
                return Stay;

            case Up:
                switch(editPhase) {
                    case 1:
                        newTime.hour = (newTime.hour < 23) ? newTime.hour+1 : 0;
                        break;
                    case 2:
                        newTime.min = (newTime.min < 55) ? newTime.min+5 : 0;
                        break;
                }
                return Stay;

            case Confirm:
                editPhase++;
                if(editPhase==3) {
                    editPhase = 1;
                    controller->autoCycleSetTStart(newTime);
                    return HomePage;
                }
                else return Stay;

            default:
                return Stay;
        }
    }

    void show() {
        if(redraw) {
            controller->displayPrint("Orario di avvio", newTime.hour, ":", newTime.min, "");
            redraw = false;
        }
    }

protected:

};

#endif
