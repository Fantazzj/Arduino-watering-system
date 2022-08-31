#ifndef HW_VALVE_CPP
#define HW_VALVE_CPP

#include "../Valve.cpp"
#include "HwClock.cpp"

class HwValve: public Valve {
private:
    int pin;

public:
    HwValve(Clock* clock, int pin, int minOn, int days) {
        init(minOn, days);
        this->pin = pin;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
        etvClock = clock;
    }

    void turnOn() {
        tOn = etvClock->getTime();
        elapsedDays = 1;
        digitalWrite(pin, LOW);
    }

    void turnOff() {
        digitalWrite(pin, HIGH);
    }
    
protected:
};

#endif
