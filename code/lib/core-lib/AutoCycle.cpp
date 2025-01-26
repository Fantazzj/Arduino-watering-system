#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock& myClock, Valve* myEtv[], int8_t etvNum, MainSwitch& myMainSwitch, Moisture& myMoisture) :
	_myClock(myClock), _myMainSwitch(myMainSwitch), _myMoisture(myMoisture) {
	_myEtv = myEtv;
	this->etvNum = etvNum;
}

void AutoCycle::begin(MyTime tStart) {
	this->tStart = tStart;
	tReset = _checkTReset();
}

int8_t AutoCycle::_nextEtv() {
	for(int8_t etv = etvOn + 1; etv < etvNum; etv++) {
		if(_myEtv[etv]->toWater()) {
			return etv;
		} else {
			_myEtv[etv]->elapsedDays++;
		}
	}
	return -1;
}

MyTime AutoCycle::_checkTReset() {
	MyTime out(0, 0, 0);

	uint16_t minToStart = tStart.hour * 60 + tStart.min;
	uint16_t minToReset = out.hour * 60 + out.min;

	uint16_t minToWater = 0;
	for(uint8_t i = 0; i < etvNum; i++) minToWater += _myEtv[i]->minOn;
	//minToWater += msSnub/3600 * etvNum;

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
	newTime = _myClock.getTime();

	if(tReset.hour == newTime.time.hour && tReset.min == newTime.time.min && !started) {
		uint8_t moisture = _myMoisture.getMoisture();
		if(moisture <= 90) {
			watered = false;
		} else {
			watered = true;
		}
	}

	if(newTime.time >= tStart && !watered && !started) {
		etvOn = _nextEtv();
		if(etvOn == -1) {
			started = false;
			watered = true;
		} else {
			started = true;
			_myMainSwitch.turnOn();
			wait(msSnub);
			_myEtv[etvOn]->turnOn();
		}
	} else if(started) {
		if(_myEtv[etvOn]->wateringDone(newTime.time)) {
			_myEtv[etvOn]->turnOff();
			wait(msSnub);
			etvOn = _nextEtv();
			if(etvOn == -1) {
				_myMainSwitch.turnOff();
				watered = true;
				started = false;
			} else {
				_myEtv[etvOn]->turnOn();
			}
		}
	}

	if(!started && etvOn != -1 && _myEtv[etvOn]->wateringDone(newTime.time)) {
		_myEtv[etvOn]->turnOff();
		wait(msSnub);
		_myMainSwitch.turnOff();
		etvOn = -1;
	}
}

void AutoCycle::updateTReset() {
	tReset = _checkTReset();
}
