#ifndef AUTO_CYCLE_HPP
#define AUTO_CYCLE_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

//#include "Debugger.hpp"
#include "MainSwitch.hpp"
#include "Moisture.hpp"
#include "Timer.hpp"
#include "ValveGroup.hpp"

class AutoCycle {
private:
	Clock& _myClock;
	ValveGroupN& _myEtv;
	MainSwitch& _myMainSwitch;
	Moisture& _myMoisture;
	Timer& _myTimer;
	//Debugger& _myDebugger;
	int8_t _nextEtv();
	MyTime _checkTReset();
	const uint16_t msSnub = 1500;

public:
	MyTime tStart;
	MyTime tReset;
	MyDateTime newTime;
	bool watered = false;
	bool started = false;
	int8_t etvOn = -1;
	int8_t etvNum;
	void updateTReset();

	explicit AutoCycle(Clock& myClock, ValveGroupN& myEtv, int8_t etvNum, MainSwitch& myMainSwitch, Moisture& myMoisture, Timer& timer/*, Debugger& debugger*/);
	void begin(MyTime tStart);
	void exec();

protected:
};

#endif//AUTO_CYCLE_HPP
