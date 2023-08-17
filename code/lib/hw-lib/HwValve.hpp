#ifndef HW_VALVE_CPP
#define HW_VALVE_CPP

#include "../Valve.cpp"

class HwValve : public Valve {
private:
	int8_t pin;

public:
	HwValve(Clock* etvClock, int8_t minOn, int8_t days, int8_t pin);
	void turnOn();
	void turnOff();

protected:
};

#endif
