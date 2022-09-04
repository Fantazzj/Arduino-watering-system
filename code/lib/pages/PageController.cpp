#ifndef PAGE_CONTROLLER_CPP
#define PAGE_CONTROLLER_CPP

#include "../Keypad.cpp"
//#include "../Debugger.cpp"
#include "../Display.cpp"
#include "../Clock.cpp"
#include "../Valve.cpp"

enum KeypadButton : int8_t {
    NoBtn,
    Cancel,
    Down,
    Up,
    Confirm
};

/*#define KeypadButton int8_t
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
    //void debugprint(char text[]) { myDebugger->printText(text); }
    //void debugprint(int8_t num) { myDebugger->printData(num); }
    void displayPrint(char text[]) { myDisplay->printSimpleText(text); }
    void displayPrint(char text[], int8_t x, int8_t y) { myDisplay->printIn(text, x, y); }
    void displayPrint(int8_t num, int8_t x, int8_t y) { myDisplay->printIn(num, x, y); }
    void displayPrint(char text1[], int8_t data, char text2[]) { myDisplay->printData(text1, data, text2); }
    void displayPrint(char text1[], int8_t data1, char text2[], int8_t data2, char text3[]) { myDisplay->printData(text1, data1, text2, data2, text3); }
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
    void displayShowCursor(int8_t x, int8_t y) { myDisplay->blinkAt(x, y); }
    void displayHideCursor() { myDisplay->noBlink(); }
    void displaySetBacklight(bool state) {
        if(state) myDisplay->backlight();
        else myDisplay->noBacklight();
    }
    int8_t getEtvOn() { return autoCycle->etvOn; }
    void setEtvOn(int8_t num) { autoCycle->etvOn = num; }
    int8_t getEtvNum() { return autoCycle->etvNum; }
    void setEtvState(int8_t num, bool state) {
        if(state) myEtv[num]->turnOn();
        else myEtv[num]->turnOff();
    }
    void setEtvDays(int8_t num, int8_t days) { myEtv[num]->days = days; }
    int8_t getEtvDays(int8_t num) { return myEtv[num]->days; }
    void setEtvMinOn(int8_t num, int8_t minOn) { myEtv[num]->minOn = minOn; }
    int8_t getEtvMinOn(int8_t num) { return myEtv[num]->minOn; }
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
