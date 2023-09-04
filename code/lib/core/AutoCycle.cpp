#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock* myClock, Valve* myEtv[], int8_t etvNum, Moisture* myMoisture, MyTime tStart) {
	_myClock = myClock;
	_myEtv = myEtv;
	this->etvNum = etvNum;
	_myMoisture = myMoisture;


	this->tStart = tStart;

	int16_t minToEndDay = tStart.hour * 60 + tStart.min;

	int16_t minToWater = 0;

	for(int8_t i = 1; i <= etvNum; i++) minToWater += myEtv[i]->minOn;

	tChange.hour = 12;
	tChange.min = 0;
	if(minToEndDay + minToWater >= 1440 /* 24*60 */) {
		tChange.hour = 0;
		tChange.min = 0;
	}
}

int8_t AutoCycle::_nextEtv() {
	for(int8_t etv = etvOn + 1; etv <= etvNum; etv++) {
		if(_myEtv[etv]->toWater()) {
			return etv;
		} else {
			_myEtv[etv]->elapsedDays++;
		}
	}
	return 0;
}

void AutoCycle::exec() {
	newTime = _myClock->getTime();

	if(newTime.time >= tStart && !watered && !started) {
		started = true;
		etvOn = _nextEtv();
		if(etvOn == 0) {
			watered = true;
			started = false;
		} else {
			_myEtv[etvOn]->turnOn();
		}
	}

	if(started) {
		if(_myEtv[etvOn]->wateringDone(newTime.time)) {
			_myEtv[etvOn]->turnOff();
			Timer::wait(1000);
			etvOn = _nextEtv();
			if(etvOn == 0) {
				watered = true;
				started = false;
			} else {
				_myEtv[etvOn]->turnOn();
			}
		}
	}

	if(!started && etvOn != 0 && _myEtv[etvOn]->wateringDone(newTime.time)) {
		_myEtv[etvOn]->turnOff();
		etvOn = 0;
	}

	if(tChange.hour == newTime.time.hour && tChange.min == newTime.time.min) {
		uint8_t moisture = _myMoisture->getMoisture();
		if(moisture < 50) watered = false;
		else watered = true;
	}
}
