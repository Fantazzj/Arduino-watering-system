#ifndef VALVE_CPP
#define VALVE_CPP

#include "MyTime.cpp"
#include "Clock.cpp"

class Valve{
private:

public:
    int8_t days;
    int8_t minOn;
    int8_t elapsedDays=1;
    MyTime tOn;

    Valve(Clock* etvClock, int8_t minOn, int8_t days) {
        this->etvClock = etvClock;
        this->minOn = minOn;
        this->days = days;
    }

    virtual void turnOn() {
        tOn = etvClock->getTime();
        elapsedDays = 1;
    }
    virtual void turnOff() {}
    bool toWater() {
        if(elapsedDays>=days and days > 0 and minOn > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool wateringDone(MyTime newTime) {
        if(MyTime::elapsedMin(tOn, newTime) >= minOn) return true;
        else return false;
    }

protected:
    Clock* etvClock;

};

#endif
