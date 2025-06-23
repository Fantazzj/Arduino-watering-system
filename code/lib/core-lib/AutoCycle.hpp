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
	Clock& _myClock;
	ValveGroupN& _myEtv;
	MainSwitch& _myMainSwitch;
	Moisture& _myMoisture;
	Timer& _myTimer;
	Debugger& _myDebugger;
	int8_t _nextEtv() const;

public:
	MyTime tStart;
	MyTime tReset;
	MyDateTime newTime;
	bool watered = false;
	bool started = false;
	int8_t etvOn = -1;
	void updateTReset();

	explicit AutoCycle(Clock& myClock, ValveGroupN& myEtv, MainSwitch& myMainSwitch, Moisture& myMoisture, Timer& timer, Debugger& debugger);
	void begin(MyTime tStart);
	void exec();
};

#endif//AUTO_CYCLE_HPP
