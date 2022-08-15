#ifndef PAGE_CONTROLLER_CPP
#define PAGE_CONTROLLER_CPP

#include "../Keypad.cpp"
#include "../Debugger.cpp"
#include "../Display.cpp"
#include "../Clock.cpp"
#include "../Valve.cpp"

enum KeypadButton : int {
    NoBtn,
    Cancel,
    Down,
    Up,
    Confirm
};

class PageController{
private:
    Keypad* myKeypad;
    Debugger* myDebugger;
    Display* myDisplay;
    Clock* myClock;
    Valve** myEtv;

public:
    PageController(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[]) {
        this->myKeypad = myKeypad;
        this->myDebugger = myDebugger;
        this->myDisplay = myDisplay;
        this->myClock = myClock;
        this->myEtv = myEtv;
    }

    KeypadButton keypad() {
        if(myKeypad->cancel()) return Cancel;
        if(myKeypad->down()) return Down;
        if(myKeypad->up()) return Up;
        if(myKeypad->confirm()) return Confirm;
        else return NoBtn;
    }
    void debugPrint(char text[]) { myDebugger->printText(text); }
    void debugPrint(int num) { myDebugger->printData(num); }
    void displayPrint(char text[]) { myDisplay->printSimpleText(text); }
    void displayPrint(char text1[], int data, char text2[]) { myDisplay->printData(text1, data, text2); }
    void displayPrint(char text1[], int data1, char text2[], int data2, char text3[]) { myDisplay->printData(text1, data1, text2, data2, text3); }
    void displayPrint(MyTime time) { myDisplay->showClock(time); }
    void displayDrop(bool state) {
        if (state) myDisplay->dropSym();
        else myDisplay->noDropSym();
    }
    int etvOn = 0;
    const int etvNum = 9;
    void setEtvState(int num, bool state) {
        if(state) myEtv[num]->turnOn();
        else myEtv[num]->turnOff();
    }
    void setEtvDays(int num, int days) { myEtv[num]->days = days; }
    int getEtvDays(int num) { return myEtv[num]->days; }
    void setEtvMinOn(int num, int minOn) { myEtv[num]->minOn = minOn; }
    int getEtvMinOn(int num) { return myEtv[num]->minOn; }
    MyTime clockGetTime() { return myClock->getTime(); }
    void clockSetTime(MyTime timeIn) { myClock->setTime(timeIn); }

protected:
};

#endif
