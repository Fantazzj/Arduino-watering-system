#ifndef QT_VALVE_CPP
#define QT_VALVE_CPP

#include "../core/Valve.hpp"
#include "ControlUnit.h"
#include <cstdint>

class QtValve : public Valve {
private:
	ControlUnit* w;
	uint8_t num;

public:
	QtValve(Clock* clock, uint8_t minOn, uint8_t days, ControlUnit* w, uint8_t num);
	void turnOn() override;
	void turnOff() override;

protected:
};

#endif