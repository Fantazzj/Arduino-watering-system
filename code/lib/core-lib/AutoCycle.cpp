#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock& myClock, ValveGroupN& myEtv, int8_t etvNum, MainSwitch& myMainSwitch, Moisture& myMoisture, Timer& myTimer) :
	_myClock(myClock), _myEtv(myEtv), _myMainSwitch(myMainSwitch), _myMoisture(myMoisture), _myTimer(myTimer) {
	this->etvNum = etvNum;
}

void AutoCycle::begin(MyTime tStart) {
	this->tStart = tStart;
	tReset = _checkTReset();
}

int8_t AutoCycle::_nextEtv() {
	for(int8_t etv = etvOn + 1; etv < etvNum; etv++) {
		if(_myEtv.toWater(etv)) {
			return etv;
		} else {
			_myEtv.setDays(etv, _myEtv.getDays(etv) + 1);
		}
	}
	return -1;
}

MyTime AutoCycle::_checkTReset() {
	MyTime out(0, 0, 0);

	uint16_t minToStart = tStart.hour * 60 + tStart.min;
	uint16_t minToReset = out.hour * 60 + out.min;

	uint16_t minToWater = 0;
	for(uint8_t i = 0; i < etvNum; i++) minToWater += _myEtv.getMinOn(i);
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
	newTime = _myClock.getDateTime();

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
			_myTimer.wait(msSnub);
			_myEtv.turnOn(etvOn);
		}
	} else if(started) {
		if(_myEtv.wateringDone(etvOn, newTime.time)) {
			_myEtv.turnOff(etvOn);
			_myTimer.wait(msSnub);
			etvOn = _nextEtv();
			if(etvOn == -1) {
				_myMainSwitch.turnOff();
				watered = true;
				started = false;
			} else {
				_myEtv.turnOn(etvOn);
			}
		}
	}

	if(!started && etvOn != -1 && _myEtv.wateringDone(etvOn, newTime.time)) {
		_myEtv.turnOff(etvOn);
		_myTimer.wait(msSnub);
		_myMainSwitch.turnOff();
		etvOn = -1;
	}
}

void AutoCycle::updateTReset() {
	tReset = _checkTReset();
}
