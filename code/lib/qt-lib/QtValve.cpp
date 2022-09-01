#ifndef QT_VALVE_CPP
#define QT_VALVE_CPP

#include "lib/Valve.cpp"
#include "QtClock.cpp"

class QtValve: public Valve {
private:
    ControlUnit* w;
    int num;

public:
    QtValve(ControlUnit* w, Clock* clock, int num, int minOn, int days) : Valve(clock, minOn, days) {
        this->w = w;
        this->num = num;
    }

    void turnOn() {
        tOn = etvClock->getTime();
        elapsedDays = 1;
        w->activate(num);
    }

    void turnOff() {
        w->deactivate(num);
    }

protected:

};

#endif