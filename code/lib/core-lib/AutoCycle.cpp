#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock& myClock, ValveGroupN& myEtv, MainSwitch& myMainSwitch, Moisture& myMoisture, Timer& myTimer, Debugger& myDebugger) :
	_myClock(myClock), _myEtv(myEtv), _myMainSwitch(myMainSwitch), _myMoisture(myMoisture), _myTimer(myTimer), _myDebugger(myDebugger) {
}

void AutoCycle::begin(const MyTime tStart) {
	this->tStart = tStart;
	updateTReset();
}

int8_t AutoCycle::_nextEtv() const {
	for(int8_t etv = etvOn + 1; etv < VALVE_NUM; etv++) {
		if(_myEtv.toWater(etv)) {
			return etv;
		}
		_myEtv.increaseElapsedDays(etv);
	}
	return -1;
}

void AutoCycle::exec() {
	newTime = _myClock.getDateTime();

	// Check if is moist
	if(watered && tReset.hour == newTime.time.hour && tReset.min == newTime.time.min) {
		const uint8_t moisture = _myMoisture.getMoisture();
		watered = moisture >= 50;
#ifdef DEBUG
		//FIXME: execution is "infinite" if is watered (moisture>90) and the debugger's buffer is continuously filled until it explodes, before enabling debugger's prints it needs to be solved
		//_myDebugger.print("Moisture level ");
		//_myDebugger.print(moisture);
		//_myDebugger.println("%");
#endif
		return;
	}

	// Automatic turn off after manual watering
	if(!started && etvOn != -1 && _myEtv.wateringDone(etvOn, newTime.time)) {
#ifdef DEBUG
		_myDebugger.print("Automatic turning off Etv ");
		_myDebugger.println(etvOn + 1);
#endif
		_myMainSwitch.turnOff();
		_myTimer.wait(MS_SNUBBER);
		_myEtv.turnOff(etvOn);
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
		_myDebugger.print("Turning on Etv ");
		_myDebugger.println(etvOn + 1);
#endif
		_myEtv.turnOn(etvOn);
		_myTimer.wait(MS_SNUBBER);
		_myMainSwitch.turnOn();

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
		_myMainSwitch.turnOff();
		_myTimer.wait(MS_SNUBBER);
		_myEtv.turnOff(etvOn);

		etvOn = _nextEtv();
		if(etvOn == -1) {
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
		_myTimer.wait(MS_SNUBBER);
		_myMainSwitch.turnOn();
	}
}

void AutoCycle::updateTReset() {
	const uintmax_t startMin = hourToMin(tStart.hour) + tStart.min;

	uint16_t minToWater = 0;
	for(int8_t e = 0; e < VALVE_NUM; e++)
		minToWater += _myEtv.getMinOn(e);
	minToWater += secToMin(MS_SNUBBER * VALVE_NUM / 1000);

	tReset = startMin + minToWater < 1440 ? MyTime(0, 0, 0) : MyTime(12, 0, 0);

#ifdef DEBUG
	_myDebugger.print("Watering state will reset at: ");
	_myDebugger.println(tReset);
#endif
}
