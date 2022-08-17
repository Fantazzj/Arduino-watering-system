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
    MyTime tChange;
    MyTime newTime;
    bool watered = false;
    bool started = false;
    int etvOn = 0;

    AutoCycle(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[], int etvNum) {
        this->myKeypad = myKeypad;
        this->myDebugger = myDebugger;
        this->myDisplay = myDisplay;
        this->myClock = myClock;
        this->myEtv = myEtv;

        tStart.hour = 14;
        tStart.min = 30;
        int minToEndDay = tStart.hour*60 + tStart.min;

        int minToWater = 0;

        for(int i=1; i<=etvNum; i++) minToWater += myEtv[i]->minOn;

        if(minToEndDay + minToWater >= 1440 /* 24*60 */) {
            tChange.hour = 0;
            tChange.min = 0;
        }
        else {
            tChange.hour = 12;
            tChange.min = 0;
        }

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

        if(MyTime::isEqual(tChange, newTime)) watered=false;

    }

protected:
};

#endif
