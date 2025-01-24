#ifndef QTGENERALSWITCH_HPP
#define QTGENERALSWITCH_HPP

#include "../core/MainSwitch.hpp"
#include "ControlUnit.h"
#include <cstdint>

class QtMainSwitch : public MainSwitch {
private:
	ControlUnit* w;

public:
	explicit QtMainSwitch();
	void begin(ControlUnit* w);
	void turnOn() override;
	void turnOff() override;
};

#endif//QTGENERALSWITCH_HPP
