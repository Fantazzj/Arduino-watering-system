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
    MyTime newTime;
    bool watered = false;
    bool started = false;
    int etvOn = 0;

    AutoCycle(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[]) {
        this->myKeypad = myKeypad;
        this->myDebugger = myDebugger;
        this->myDisplay = myDisplay;
        this->myClock = myClock;
        this->myEtv = myEtv;

        tStart.hour = 14;
        tStart.min = 30;
    }

    void exec() {

        newTime = myClock->getTime();

        if (MyTime::isGreaterOrEq(newTime, tStart) && !watered && !started) {
            started = true;
            etvOn = 1;
            myEtv[etvOn]->turnOn();
        }

        if (started) {
            if (MyTime::elapsedMin(myEtv[etvOn]->tOn, newTime) >= myEtv[etvOn]->minOn) {
                myEtv[etvOn]->turnOff();
                etvOn++;
                if (etvOn >= 10) {
                    etvOn = 0;
                    watered = true;
                    started = false;
                } else myEtv[etvOn]->turnOn();
            }
        }
    }

protected:
};

#endif
