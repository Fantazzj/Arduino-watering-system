#ifndef VALVE_CPP
#define VALVE_CPP

#include "MyTime.cpp"
#include "Clock.cpp"

class Valve{
private:

public:
    Valve() {}

    int days;
    int minOn;
    int elapsedDays=0;
    MyTime tOn;

    virtual void turnOn() {}
    virtual void turnOff() {}

protected:
    Clock* etvClock;

};

#endif
