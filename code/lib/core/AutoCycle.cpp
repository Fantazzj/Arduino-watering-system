#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock* myClock, Valve* myEtv[], int8_t etvNum, Moisture* myMoisture, MyTime tStart) {
	_myClock = myClock;
	_myEtv = myEtv;
	this->etvNum = etvNum;
	_myMoisture = myMoisture;


	this->tStart = tStart;

	tReset = _checkTReset();
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

MyTime AutoCycle::_checkTReset() {
	MyTime out = {0, 0, 0};

	uint16_t minToStart = tStart.hour * 60 + tStart.min;
	uint16_t minToReset = out.hour * 60 + out.min;

	uint16_t minToWater = 0;
	for(int8_t i = 1; i <= etvNum; i++) minToWater += _myEtv[i]->minOn;

	if(minToStart + minToWater > 1440 + minToReset) {
		//TODO verify
		uint16_t minToWater1 = (minToStart + minToWater) - 1440;
		//uint16_t minToWater2 = minToWater - minToWater1;
		uint16_t freeTime = 1440 - minToWater;

		minToReset = minToWater1 + freeTime / 2;
		out.hour = minToReset / 60;
		out.min = minToReset % 60;
	}

	return out;
}

void AutoCycle::exec() {
	newTime = _myClock->getTime();

	if(tReset.hour == newTime.time.hour && tReset.min == newTime.time.min && !started) {
		uint8_t moisture = _myMoisture->getMoisture();
		if(moisture <= 50) watered = false;
		else watered = true;
	}

	if(newTime.time >= tStart && !watered && !started) {
		etvOn = _nextEtv();
		if(etvOn == 0) {
			started = false;
			watered = true;
		} else {
			started = true;
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
}

void AutoCycle::updateTReset() {
	tReset = _checkTReset();
}
