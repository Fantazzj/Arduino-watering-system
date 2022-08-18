#ifndef VALVE_CPP
#define VALVE_CPP

#include "MyTime.cpp"
#include "Clock.cpp"

class Valve{
private:

public:
    Valve(int minOn, int days) {
        this->minOn = minOn;
        this->days = days;
    }

    int days;
    int minOn;
    int elapsedDays=1;
    MyTime tOn;

    virtual void turnOn() {}
    virtual void turnOff() {}
    bool toWater() {
        if(elapsedDays>=days and days > 0 and minOn > 0) return true;
        else false;
    }
    bool wateringDone(MyTime newTime) {
        if(MyTime::elapsedMin(tOn, newTime) >= minOn) return true;
        else return false;
    }

protected:
    Clock* etvClock;

};

#endif
