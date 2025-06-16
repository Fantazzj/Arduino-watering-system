#ifndef CLAYVALVEGROUP_HPP
#define CLAYVALVEGROUP_HPP

#include "../core-lib/ValveGroup.hpp"
#include "ClayControlUnit.hpp"

class ClayValveGroup final : public ValveGroupN {
private:
	ClayControlUnit* w;

public:
	explicit ClayValveGroup(Clock& clock);
	void begin(ClayControlUnit* w);
	void turnOn(uint8_t num) override;
	void turnOff(uint8_t num) override;

protected:
};

#endif//CLAYVALVEGROUP_HPP
