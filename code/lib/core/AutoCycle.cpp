#include "AutoCycle.hpp"

AutoCycle::AutoCycle(Clock& clock, ValveGroupN& etv, MainSwitch& mainSwitch, Moisture& moisture, Timer& timer, Debugger& debugger) :
	clock(clock), etv(etv), mainSwitch(mainSwitch), moisture(moisture), timer(timer), debugger(debugger) {
	watered = false;
	started = false;
	moist = false;
	etvOn = -1;
}

void AutoCycle::begin(const MyTime tStart) {
	this->tStart = tStart;
	updateTReset();
}

int8_t AutoCycle::chooseNextEtv() const {
	for(int8_t e = etvOn + 1; e < VALVE_NUM; e++) {
		if(etv.toWater(e)) {
			return e;
		}
		etv.increaseElapsedDays(e);
	}
	return -1;
}

void AutoCycle::exec() {
	newTime = clock.getDateTime();

	// Reset watered state
	if(watered && tReset.hour == newTime.time.hour && tReset.min == newTime.time.min) {
		watered = false;
		return;
	}

	// Automatic turn off after manual watering
	if(!started && etvOn != -1 && etv.wateringDone(etvOn, newTime.time)) {
#ifdef DEBUG
		debugger.print("Automatic turning off Etv ");
		debugger.println(etvOn + 1);
#endif
		mainSwitch.turnOff();
		timer.wait(MS_SNUBBER);
		etv.turnOff(etvOn);
		etvOn = -1;
		return;
	}

	// Start the watering
	if(newTime.time >= tStart && !watered && !started) {
		if(moisture.getMoisture() >= 50) {
			started = false;
			watered = true;
			moist = true;
#ifdef DEBUG
			debugger.println("Today is already moist");
			debugger.print("Moisture level ");
			debugger.print(moisture.getMoisture());
			debugger.println("%");
#endif
			return;
		}

		moist = false;
		etvOn = chooseNextEtv();
		if(etvOn == -1) {
			started = false;
			watered = true;
#ifdef DEBUG
			debugger.println("Today no etv needs watering");
#endif
			return;
		}
#ifdef DEBUG
		debugger.println("Watering starts");
#endif
		started = true;
#ifdef DEBUG
		debugger.print("Turning on Etv ");
		debugger.println(etvOn + 1);
#endif
		etv.turnOn(etvOn);
		timer.wait(MS_SNUBBER);
		mainSwitch.turnOn();

		return;
	}

	// Continue the watering
	if(started) {
		if(!etv.wateringDone(etvOn, newTime.time))
			return;

#ifdef DEBUG
		debugger.print("Turning off Etv ");
		debugger.println(etvOn + 1);
#endif
		mainSwitch.turnOff();
		timer.wait(MS_SNUBBER);
		etv.turnOff(etvOn);

		etvOn = chooseNextEtv();
		if(etvOn == -1) {
			watered = true;
			started = false;
#ifdef DEBUG
			debugger.println("Watering finished");
#endif
			return;
		}
#ifdef DEBUG
		debugger.print("Turning on Etv ");
		debugger.println(etvOn + 1);
#endif
		etv.turnOn(etvOn);
		timer.wait(MS_SNUBBER);
		mainSwitch.turnOn();
	}
}

uint8_t AutoCycle::getMinToWater() const {
	uint16_t minToWater = 0;
	for(int8_t e = 0; e < VALVE_NUM; e++)
		minToWater += etv.getMinOn(e);
	minToWater += secToMin(MS_SNUBBER * VALVE_NUM / 1000);

	return minToWater;
}

void AutoCycle::updateTReset() {
	const uintmax_t startMin = hourToMin(tStart.hour) + tStart.min;

	tReset = startMin + getMinToWater() < 1440 ? MyTime(0, 0, 0) : MyTime(12, 0, 0);

#ifdef DEBUG
	debugger.print("Watering state will reset at: ");
	debugger.println(tReset);
#endif
}
