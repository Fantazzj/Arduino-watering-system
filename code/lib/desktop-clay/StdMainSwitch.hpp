#ifndef CLAYMAINSWITCH_HPP
#define CLAYMAINSWITCH_HPP

#include "../core/MainSwitch.hpp"

class StdMainSwitch final : public MainSwitch {
public:
	explicit StdMainSwitch();
	void turnOn() override;
	void turnOff() override;
	[[nodiscard]] bool getState() const;

private:
	bool state;
};

#endif//CLAYMAINSWITCH_HPP
