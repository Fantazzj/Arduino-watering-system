#ifndef AUTO_CYCLE_CPP
#define AUTO_CYCLE_CPP

class AutoCycle {
private:
    Keypad* myKeypad;
    Debugger* myDebugger;
    Display* myDisplay;
    Clock* myClock;
    Valve** myEtv;
    AutoCycle* autoCycle;

public:
    MyTime tStart;
    bool watered = false;

    AutoCycle(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[]) {
        this->myKeypad = myKeypad;
        this->myDebugger = myDebugger;
        this->myDisplay = myDisplay;
        this->myClock = myClock;
        this->myEtv = myEtv;

        tStart.hour = 109;
        tStart.min = 30;
    }

    void exec() {
        if(tStart.hour < 19) myEtv[1]->turnOn();
        else myEtv[1]->turnOff();
    }

protected:
};

#endif
