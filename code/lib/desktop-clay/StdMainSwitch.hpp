#pragma once

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
