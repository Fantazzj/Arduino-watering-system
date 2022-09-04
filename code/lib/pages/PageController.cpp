#ifndef PAGE_CONTROLLER_CPP
#define PAGE_CONTROLLER_CPP

#include "../Keypad.cpp"
//#include "../Debugger.cpp"
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

/*#define KeypadButton int
#define NoBtn 0
#define Cancel 1
#define Down 2
#define Up 3
#define Confirm 4*/

class PageController{
private:
    Keypad* myKeypad;
    //Debugger* myDebugger;
    Display* myDisplay;
    Clock* myClock;
    Valve** myEtv;
    AutoCycle* autoCycle;
    bool timeToEdit;

public:
    PageController(Keypad* myKeypad/*, Debugger* myDebugger*/, Display* myDisplay, Clock* myClock, Valve* myEtv[], AutoCycle* autoCycle) {
        this->myKeypad = myKeypad;
        //this->myDebugger = myDebugger;
        this->myDisplay = myDisplay;
        this->myClock = myClock;
        this->myEtv = myEtv;
        this->autoCycle = autoCycle;
        timeToEdit = true;
    }

    KeypadButton keypad() {
        if(myKeypad->cancel()) return Cancel;
        if(myKeypad->down()) return Down;
        if(myKeypad->up()) return Up;
        if(myKeypad->confirm()) return Confirm;
        else return NoBtn;
    }
    bool getTimeToEdit() { return timeToEdit; }
    bool setTimeToEdit(bool state) { timeToEdit=state; }
    bool keypadGeneral() { return myKeypad->generalPressed(); }
    //void debugPrint(char text[]) { myDebugger->printText(text); }
    //void debugPrint(int num) { myDebugger->printData(num); }
    void displayPrint(char text[]) { myDisplay->printSimpleText(text); }
    void displayPrint(char text[], int x, int y) { myDisplay->printIn(text, x, y); }
    void displayPrint(int num, int x, int y) { myDisplay->printIn(num, x, y); }
    void displayPrint(char text1[], int data, char text2[]) { myDisplay->printData(text1, data, text2); }
    void displayPrint(char text1[], int data1, char text2[], int data2, char text3[]) { myDisplay->printData(text1, data1, text2, data2, text3); }
    void displayPrint(MyTime time) { myDisplay->showClock(time); }
    void displayDrop(bool state) {
        if(state) myDisplay->dropSym();
        else myDisplay->noDropSym();
    }
    void displayClock(bool state) {
        if(state) myDisplay->clockSym();
        else myDisplay->noClockSym();
    }
    void displayCheck(bool state) {
        if(state) myDisplay->checkSym();
        else myDisplay->noCheckSym();
    }
    void displayShowCursor(int x, int y) { myDisplay->blinkAt(x, y); }
    void displayHideCursor() { myDisplay->noBlink(); }
    void displaySetBacklight(bool state) {
        if(state) myDisplay->backlight();
        else myDisplay->noBacklight();
    }
    int getEtvOn() { return autoCycle->etvOn; }
    void setEtvOn(int num) { autoCycle->etvOn = num; }
    int getEtvNum() { return autoCycle->etvNum; }
    void setEtvState(int num, bool state) {
        if(state) myEtv[num]->turnOn();
        else myEtv[num]->turnOff();
    }
    void setEtvDays(int num, int days) { myEtv[num]->days = days; }
    int getEtvDays(int num) { return myEtv[num]->days; }
    void setEtvMinOn(int num, int minOn) { myEtv[num]->minOn = minOn; }
    int getEtvMinOn(int num) { return myEtv[num]->minOn; }
    MyTime clockGetTime() { return myClock->getTime(); }
    void clockSetTime(MyTime timeIn) { 
        myClock->setTime(timeIn);
        setTimeToEdit(false);
    }
    void autoCycleSetWatered(bool mode) { autoCycle->watered = mode; }
    bool autoCycleGetWatered() { return autoCycle->watered; }
    void autoCycleSetStarted(bool mode) { autoCycle->started = mode; }
    bool autoCycleGetStarted() { return autoCycle->started; }
    void autoCycleSetTStart(MyTime timeIn) { autoCycle->tStart = timeIn; }
    MyTime autoCycleGetTStart() { return autoCycle->tStart; }


protected:
};

#endif
