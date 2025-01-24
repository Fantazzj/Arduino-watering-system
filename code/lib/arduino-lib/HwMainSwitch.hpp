#ifndef HWMAINSWITCH_HPP
#define HWMAINSWITCH_HPP

#include "../core/MainSwitch.hpp"
#include <Arduino.h>

class HwMainSwitch : public MainSwitch {
private:
	int8_t pin;

public:
	explicit HwMainSwitch(int8_t pin);
	void turnOn() override;
	void turnOff() override;
};

#endif
