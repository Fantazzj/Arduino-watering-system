#ifndef CLAYMAINSWITCH_HPP
#define CLAYMAINSWITCH_HPP

#include "../core/MainSwitch.hpp"
#include "ClayControlUnit.hpp"

class ClayMainSwitch final : public MainSwitch {
private:
	ClayControlUnit* w;

public:
	explicit ClayMainSwitch();
	void begin(ClayControlUnit* w);
	void turnOn() override;
	void turnOff() override;

protected:
};

#endif//CLAYMAINSWITCH_HPP
