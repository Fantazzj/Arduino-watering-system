#pragma once

#include "../core/ValveGroup.hpp"

class StdValveGroup final : public ValveGroupN {
public:
	explicit StdValveGroup(Clock& clock);
	void turnOn(uint8_t num) override;
	void turnOff(uint8_t num) override;
	[[nodiscard]] const bool* getStates() const;

private:
	bool states[VALVE_NUM];
};
