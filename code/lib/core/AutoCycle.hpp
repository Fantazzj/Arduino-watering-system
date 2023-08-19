#ifndef AUTO_CYCLE_HPP
#define AUTO_CYCLE_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "Moisture.hpp"
#include "Valve.hpp"

class AutoCycle {
private:
	Clock* _myClock;
	Valve** _myEtv;
	int8_t _nextEtv();

public:
	MyTime tStart;
	MyTime tChange;
	MyTime newTime;
	bool watered = false;
	bool started = false;
	int8_t etvOn = 0;
	int8_t etvNum;
	Moisture* _myMoisture;

	AutoCycle(Clock* myClock, Valve* myEtv[], int8_t etvNum, Moisture* myMoisture);
	void exec();

protected:
};

#endif//AUTO_CYCLE_HPP
