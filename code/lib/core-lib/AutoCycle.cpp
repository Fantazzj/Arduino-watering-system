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
			_myEtv.increaseElapsedDays(etv);
		}
	}
	return -1;
}

MyTime AutoCycle::_checkTReset() {
	MyTime out(0, 0, 0);

	uint16_t minToStart = hourToMin(tStart.hour) + tStart.min;
	uint16_t minToReset = hourToMin(out.hour) + out.min;

	uint16_t minToWater = 0;
	for(uint8_t i = 0; i < etvNum; i++) {
		minToWater += _myEtv.getMinOn(i);
		minToWater += secToMin(msSnub / 1000);
	}

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

	// Check if is moist
	if(!watered && tReset.hour == newTime.time.hour && tReset.min == newTime.time.min) {
		uint8_t moisture = _myMoisture.getMoisture();
		watered = moisture > 90;
		return;
	}

	// Automatic turn off after manual watering
	if(!started && etvOn != -1 && _myEtv.wateringDone(etvOn, newTime.time)) {
		_myEtv.turnOff(etvOn);
		_myTimer.wait(msSnub);
		_myMainSwitch.turnOff();
		etvOn = -1;
		return;
	}

	// Start the watering
	if(newTime.time >= tStart && !watered && !started) {
		etvOn = _nextEtv();

		if(etvOn == -1) {
			started = false;
			watered = true;
			return;
		}

		started = true;
		_myMainSwitch.turnOn();
		_myTimer.wait(msSnub);
		_myEtv.turnOn(etvOn);
		return;
	}

	// Continue the watering
	if(started) {
		if(!_myEtv.wateringDone(etvOn, newTime.time))
			return;

		_myEtv.turnOff(etvOn);
		_myTimer.wait(msSnub);

		etvOn = _nextEtv();
		if(etvOn == -1) {
			_myMainSwitch.turnOff();
			watered = true;
			started = false;
			return;
		}

		_myEtv.turnOn(etvOn);
	}
}

void AutoCycle::updateTReset() {
	tReset = _checkTReset();
}
