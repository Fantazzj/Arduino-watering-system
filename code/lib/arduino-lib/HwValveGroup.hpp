#ifndef HWVALVEGROUP_HPP
#define HWVALVEGROUP_HPP

#include "../core-lib/ValveGroup.hpp"

class HwValveGroup : public ValveGroupN {
private:
	int8_t etvsPin[VALVE_NUM];

public:
	explicit HwValveGroup(Clock& clock, uint8_t* days, uint8_t* minOn, const int8_t* etvsPin);
	explicit HwValveGroup(Clock& clock, const int8_t* etvsPin);
	void begin();
	void turnOn(uint8_t num) override;
	void turnOff(uint8_t num) override;

protected:
};

#endif
