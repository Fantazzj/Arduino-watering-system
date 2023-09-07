#ifndef AUTO_CYCLE_HPP
#define AUTO_CYCLE_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "MainSwitch.hpp"
#include "Moisture.hpp"
#include "Valve.hpp"
#include "Overrider.hpp"

class AutoCycle {
private:
	Clock* _myClock;
	Valve** _myEtv;
	MainSwitch* _myMainSwitch;
	Moisture* _myMoisture;
	int8_t _nextEtv();
	MyTime _checkTReset();
	const uint16_t msSnub = 1500;

public:
	MyTime tStart;
	MyTime tReset;
	MyDateTime newTime;
	bool watered = false;
	bool started = false;
	int8_t etvOn = 0;
	int8_t etvNum;
	void updateTReset();

	AutoCycle(Clock* myClock, Valve* myEtv[], int8_t etvNum, MainSwitch* myMainSwitch, Moisture* myMoisture, MyTime tStart);
	void exec();

protected:
};

#endif//AUTO_CYCLE_HPP
