#ifndef AUTO_CYCLE_HPP
#define AUTO_CYCLE_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "MainSwitch.hpp"
#include "Moisture.hpp"
#include "Overrider.hpp"
#include "Valve.hpp"

class AutoCycle {
private:
	Clock& _myClock;
	Valve** _myEtv;
	MainSwitch& _myMainSwitch;
	Moisture& _myMoisture;
	uint8_t _nextEtv();
	MyTime _checkTReset();
	const uint16_t msSnub = 1500;

public:
	MyTime tStart;
	MyTime tReset;
	MyDateTime newTime;
	bool watered = false;
	bool started = false;
	uint8_t etvOn = 0;
	uint8_t etvNum;
	void updateTReset();

	explicit AutoCycle(Clock& myClock, Valve* myEtv[], uint8_t etvNum, MainSwitch& myMainSwitch, Moisture& myMoisture, MyTime tStart);
	void exec();

protected:
};

#endif//AUTO_CYCLE_HPP
