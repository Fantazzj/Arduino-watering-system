#ifndef AUTO_CYCLE_HPP
#define AUTO_CYCLE_HPP

#include "Debugger.hpp"
#include "MainSwitch.hpp"
#include "Moisture.hpp"
#include "Timer.hpp"
#include "ValveGroup.hpp"

class AutoCycle {
private:
	static constexpr uint16_t MS_SNUBBER = 500;
	Clock& clock;
	ValveGroupN& etv;
	MainSwitch& mainSwitch;
	Moisture& moisture;
	Timer& timer;
	Debugger& debugger;
	int8_t chooseNextEtv() const;

public:
	MyTime tStart;
	MyTime tReset;
	MyDateTime newTime;
	bool watered = false;
	bool started = false;
	int8_t etvOn = -1;
	explicit AutoCycle(Clock& clock, ValveGroupN& etv, MainSwitch& mainSwitch, Moisture& moisture, Timer& timer, Debugger& debugger);
	void begin(MyTime tStart);
	void exec();
	void updateTReset();
	uint8_t getMinToWater() const;
};

#endif//AUTO_CYCLE_HPP
