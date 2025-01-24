#ifndef HW_VALVE_CPP
#define HW_VALVE_CPP

#include "../core/Valve.hpp"

class HwValve : public Valve {
private:
	uint8_t pin;

public:
	explicit HwValve(Clock* etvClock, uint8_t minOn, uint8_t days, uint8_t pin);
	void turnOn() override;
	void turnOff() override;

protected:
};

#endif
