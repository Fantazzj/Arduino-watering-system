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
    int nextEtv() {
        for(int etv = etvOn+1; etv<=etvNum; etv++) {
            if(myEtv[etv]->toWater()) return etv;
            else myEtv[etv]->elapsedDays++;
        }
        return 0;
    }

public:
    MyTime tStart;
    MyTime tChange;
    MyTime newTime;
    bool watered = false;
    bool started = false;
    int etvOn = 0;
    int oldEtvOn = 0;
    int etvNum;

    AutoCycle(Keypad* myKeypad, Debugger* myDebugger, Display* myDisplay, Clock* myClock, Valve* myEtv[], int etvNum) {
        this->myKeypad = myKeypad;
        this->myDebugger = myDebugger;
        this->myDisplay = myDisplay;
        this->myClock = myClock;
        this->myEtv = myEtv;

        this->etvNum = etvNum;

        tStart.hour = 14;
        tStart.min = 30;
        int minToEndDay = tStart.hour*60 + tStart.min;

        int minToWater = 0;

        for(int i=1; i<=etvNum; i++) minToWater += myEtv[i]->minOn;

        tChange.hour = 12;
        tChange.min = 0;
        if(minToEndDay + minToWater >= 1440 /* 24*60 */) {
            tChange.hour = 0;
            tChange.min = 0;
        }

    }

    void exec() {

        newTime = myClock->getTime();

        if(MyTime::isGreaterOrEq(newTime, tStart) and !watered and !started) {
            started = true;
            etvOn = nextEtv();
            myEtv[etvOn]->turnOn();
        }

        if(started) {
            if(myEtv[etvOn]->wateringDone(newTime)) {
                myEtv[etvOn]->turnOff();
                etvOn = nextEtv();
                if(etvOn == 0) {
                    watered = true;
                    started = false;
                }
                else {
                    myEtv[etvOn]->turnOn();
                }
            }
        }

        if(!started && etvOn!=0) {

        }

    }

protected:
};

#endif
