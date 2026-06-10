#ifndef CLAYVALVEGROUP_HPP
#define CLAYVALVEGROUP_HPP

#include "../core/ValveGroup.hpp"

class ClayValveGroup final : public ValveGroupN {
public:
	explicit ClayValveGroup(Clock& clock);
	void turnOn(uint8_t num) override;
	void turnOff(uint8_t num) override;
	[[nodiscard]] const bool* getStates() const;

private:
	bool states[VALVE_NUM];
};

#endif//CLAYVALVEGROUP_HPP
