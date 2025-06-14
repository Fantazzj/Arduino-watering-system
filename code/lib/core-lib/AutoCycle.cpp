#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock& myClock, ValveGroupN& myEtv, int8_t etvNum, MainSwitch& myMainSwitch, Moisture& myMoisture, Timer& myTimer, Debugger& myDebugger) :
	_myClock(myClock), _myEtv(myEtv), _myMainSwitch(myMainSwitch), _myMoisture(myMoisture), _myTimer(myTimer), _myDebugger(myDebugger) {
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
	uintmax_t startMin = hourToSec(tStart.hour) + minToSec(tStart.min) + tStart.sec;

	uint16_t minToWater = 0;
	for(int8_t e = 0; e < etvNum; e++)
		minToWater += _myEtv.getMinOn(e);
	minToWater += secToMin(msSnub * etvNum / 1000);

	return startMin + minToWater < 1440 ? MyTime(0, 0, 0) : MyTime(12, 0, 0);
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
#ifdef DEBUG
			_myDebugger.println("Watering not needed");
#endif
			return;
		}
#ifdef DEBUG
		_myDebugger.println("Watering starts");
#endif
		started = true;

#ifdef DEBUG
		_myDebugger.println("Turning on Main Switch");
#endif
		_myMainSwitch.turnOn();

		_myTimer.wait(msSnub);

#ifdef DEBUG
		_myDebugger.print("Turning on Etv ");
		_myDebugger.println(etvOn + 1);
#endif
		_myEtv.turnOn(etvOn);

		return;
	}

	// Continue the watering
	if(started) {
		if(!_myEtv.wateringDone(etvOn, newTime.time))
			return;
#ifdef DEBUG
		_myDebugger.print("Turning off Etv ");
		_myDebugger.println(etvOn + 1);
#endif
		_myEtv.turnOff(etvOn);
		_myTimer.wait(msSnub);

		etvOn = _nextEtv();
		if(etvOn == -1) {
#ifdef DEBUG
			_myDebugger.println("Turning off Main Switch");
#endif
			_myMainSwitch.turnOff();
			watered = true;
			started = false;
#ifdef DEBUG
			_myDebugger.println("Watering finished");
#endif
			return;
		}
#ifdef DEBUG
		_myDebugger.print("Turning on Etv ");
		_myDebugger.println(etvOn + 1);
#endif
		_myEtv.turnOn(etvOn);
	}
}

void AutoCycle::updateTReset() {
	tReset = _checkTReset();
#ifdef DEBUG
	_myDebugger.print("Watering state will reset at: ");
	_myDebugger.println(tReset);
#endif
}