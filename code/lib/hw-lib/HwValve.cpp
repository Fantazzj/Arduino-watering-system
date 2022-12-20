#ifndef HW_VALVE_CPP
#define HW_VALVE_CPP

#include "../Valve.cpp"

class HwValve : public Valve {
private:
	int8_t pin;

public:
	HwValve(Clock* etvClock, int8_t minOn, int8_t days, int8_t pin) :
		Valve(etvClock, minOn, days) {
		this->pin = pin;
		pinMode(pin, OUTPUT);
		digitalWrite(pin, HIGH);
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
