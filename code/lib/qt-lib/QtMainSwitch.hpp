#ifndef QTGENERALSWITCH_HPP
#define QTGENERALSWITCH_HPP

#include "../core-lib/MainSwitch.hpp"
#include "QtControlUnit.hpp"
#include <cstdint>

class QtMainSwitch : public MainSwitch {
private:
	QtControlUnit* w;

public:
	explicit QtMainSwitch();
	void begin(QtControlUnit* w);
	void turnOn() override;
	void turnOff() override;
};

#endif//QTGENERALSWITCH_HPP
