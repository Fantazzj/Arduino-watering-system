#ifndef AUTO_CYCLE_CPP
#define AUTO_CYCLE_CPP

class AutoCycle {
private:
    Clock* myClock;
    Valve** myEtv;
    int8_t _nextEtv() {
        for(int8_t etv = etvOn+1; etv<=etvNum; etv++) {
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
    int8_t etvOn = 0;
    int8_t etvNum;

    AutoCycle(Clock* myClock, Valve* myEtv[], int8_t etvNum) {
        this->myClock = myClock;
        this->myEtv = myEtv;
        this->etvNum = etvNum;

        tStart.hour = 0;
        tStart.min = 30;
        int16_t minToEndDay = tStart.hour*60 + tStart.min;

        int16_t minToWater = 0;

        for(int8_t i=1; i<=etvNum; i++) minToWater += myEtv[i]->minOn;

        tChange.hour = 12;
        tChange.min = 0;
        if(minToEndDay + minToWater >= 1440 /* 24*60 */) {
            tChange.hour = 0;
            tChange.min = 0;
        }

    }

    void exec() {

        newTime = myClock->getTime();

        if(MyTime::timeIsNextOrEq(newTime, tStart) and !watered and !started) {
            started = true;
            etvOn = _nextEtv();
            if(etvOn == 0) {
                watered = true;
                started = false;
            }
            else {
                myEtv[etvOn]->turnOn();
            }
        }

        if(started) {
            if(myEtv[etvOn]->wateringDone(newTime)) {
                myEtv[etvOn]->turnOff();
                etvOn = _nextEtv();
                if(etvOn == 0) {
                    watered = true;
                    started = false;
                }
                else {
                    myEtv[etvOn]->turnOn();
                }
            }
        }

        if(!started and etvOn!=0 and myEtv[etvOn]->wateringDone(newTime)) {
            myEtv[etvOn]->turnOff();
            etvOn = 0;
        }

    }

protected:
};

#endif
