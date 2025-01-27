#ifndef QTVALVEGROUP_HPP
#define QTVALVEGROUP_HPP

#include "../core-lib/ValveGroup.hpp"
#include "ControlUnit.h"

template<uint8_t n>
class QtValveGroup : public ValveGroup<n> {
private:
	ControlUnit* w;

public:
	QtValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn);
	QtValveGroup(Clock& clock);
	void turnOn(uint8_t num) override;
	void turnOff(uint8_t num) override;

protected:
};


#endif//QTVALVEGROUP_HPP
