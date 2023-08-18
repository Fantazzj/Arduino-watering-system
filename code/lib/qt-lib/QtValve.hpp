#ifndef QT_VALVE_CPP
#define QT_VALVE_CPP

#include "lib/ControlUnit.h"
#include "lib/Valve.hpp"
#include <cstdint>

class QtValve : public Valve {
private:
	ControlUnit* w;
	int num;

public:
	QtValve(Clock* clock, int8_t minOn, int8_t days, ControlUnit* w, int8_t num);
	void turnOn();
	void turnOff();

protected:
};

#endif