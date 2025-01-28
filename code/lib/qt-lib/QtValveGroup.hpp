#ifndef QTVALVEGROUP_HPP
#define QTVALVEGROUP_HPP

#include "../core-lib/ValveGroup.hpp"
#include "ControlUnit.h"

class QtValveGroup : public ValveGroupN {
private:
	ControlUnit* w;

public:
	explicit QtValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn);
	explicit QtValveGroup(Clock& clock);
	void begin(ControlUnit* w);
	void turnOn(uint8_t num) override;
	void turnOff(uint8_t num) override;

protected:
};

#endif//QTVALVEGROUP_HPP
