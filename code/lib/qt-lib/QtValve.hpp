#ifndef QT_VALVE_CPP
#define QT_VALVE_CPP

#include "../core-lib/Valve.hpp"
#include "ControlUnit.h"
#include <cstdint>

class QtValve : public Valve {
private:
	ControlUnit* w;
	uint8_t num;

public:
	explicit QtValve(Clock& clock, uint8_t minOn, uint8_t days, uint8_t num);
	explicit QtValve(Clock& clock, uint8_t num);
	void begin(ControlUnit* w);
	void turnOn() override;
	void turnOff() override;

protected:
};

#endif