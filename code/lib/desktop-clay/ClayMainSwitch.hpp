#ifndef CLAYMAINSWITCH_HPP
#define CLAYMAINSWITCH_HPP

#include "../core/MainSwitch.hpp"

class ClayMainSwitch final : public MainSwitch {
public:
	explicit ClayMainSwitch();
	void turnOn() override;
	void turnOff() override;
	[[nodiscard]] bool getState() const;

private:
	bool state;
};

#endif//CLAYMAINSWITCH_HPP
