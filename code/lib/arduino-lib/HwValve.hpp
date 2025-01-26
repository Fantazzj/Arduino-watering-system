#ifndef HW_VALVE_CPP
#define HW_VALVE_CPP

#include "../core-lib/Valve.hpp"

class HwValve : public Valve {
private:
	uint8_t pin;

public:
	explicit HwValve(Clock& etvClock, uint8_t minOn, uint8_t days, uint8_t pin);
	explicit HwValve(Clock& etvClock, uint8_t pin);
	void begin();
	void turnOn() override;
	void turnOff() override;

protected:
};

#endif
