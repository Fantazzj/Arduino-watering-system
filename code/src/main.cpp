#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/PageSelector.hpp"

#if defined(HWARDUINO)
#	include "../lib/hardware-arduino/HwClock.hpp"
#	include "../lib/hardware-arduino/HwDisplay.hpp"
#	include "../lib/hardware-arduino/HwKeypad.hpp"
#	include "../lib/hardware-arduino/HwMainSwitch.hpp"
#	include "../lib/hardware-arduino/HwMemory.hpp"
#	include "../lib/hardware-arduino/HwMoisture.hpp"
#	include "../lib/hardware-arduino/HwValveGroup.hpp"
#	include "../lib/hardware-arduino/HwDebugger.hpp"
#	include "../lib/hardware-arduino/HwTimer.hpp"

//UnitDisplay
#	define lcdAddress 0x27
#	define lcdLength 16
#	define lcdHeight 2

//Etv
constexpr int8_t etvsPin[] = {6, 7, 2, 3, 4, 5, 8, 9, 10};
#	define mainSwitchPin 11

//Buttons
#	define cancelPin A3
#	define downPin A1
#	define upPin A2
#	define confirmPin A0

//Sensors
#	define humidityPin A7

//Serial
#	define baud 115200

HwKeypad myKeypad(cancelPin, downPin, upPin, confirmPin);
HwDisplay myDisplay(lcdAddress, lcdLength, lcdHeight);
HwClock myClock;
HwValveGroup myValveGroup(myClock, etvsPin);
HwMainSwitch myMainSwitch(mainSwitchPin);
HwMemory myMemory;
HwMoisture myMoisture(humidityPin);
HwDebugger myDebugger;
HwTimer myTimer;
#elif defined(CLAYDESKTOP)
#	include "../lib/desktop-clay/ClayControlUnit.hpp"
#	include "../lib/desktop-clay/ClayClock.hpp"
#	include "../lib/desktop-clay/ClayDisplay.hpp"
#	include "../lib/desktop-clay/ClayKeypad.hpp"
#	include "../lib/desktop-clay/ClayMainSwitch.hpp"
#	include "../lib/desktop-clay/ClayMemory.hpp"
#	include "../lib/desktop-clay/ClayMoisture.hpp"
#	include "../lib/desktop-clay/ClayValveGroup.hpp"
#	include "../lib/desktop-clay/ClayDebugger.hpp"
#	include "../lib/desktop-clay/ClayTimer.hpp"

#	include <chrono>
#	include <thread>
#	include <iostream>

using std::thread;
using std::chrono::microseconds;
using std::this_thread::sleep_for;

ClayKeypad myKeypad;
ClayDisplay myDisplay;
ClayClock myClock;
ClayValveGroup myValveGroup(myClock);
ClayMainSwitch myMainSwitch;
ClayMemory myMemory("./memory.bin");
ClayMoisture myMoisture;
ClayDebugger myDebugger;
ClayTimer myTimer;
#else
#	error "No variable definition"
#endif

AutoCycle autoCycle(myClock, myValveGroup, myMainSwitch, myMoisture, myTimer, myDebugger);
PageSelector pageSelector(myKeypad, myDisplay, myClock, myValveGroup, myMainSwitch, myMemory, myTimer, myDebugger, autoCycle);

#if defined(HWARDUINO)
void setup() {
	myDisplay.begin();
	myClock.begin();
	myMainSwitch.begin();
	myKeypad.begin(INPUT_PULLUP);
	myMemory.begin();
	myValveGroup.begin();
	myDebugger.begin(115200);

	for(int8_t i = 0; i < VALVE_NUM; i++) {
		myValveGroup.setMinOn(i, myMemory.readEtvMinOn(i));
		myValveGroup.setDays(i, myMemory.readEtvDays(i));
	}

	MyTime tStart = myMemory.readStartTime();

	autoCycle.begin(tStart);
	pageSelector.begin();
}
#elif defined(CLAYDESKTOP)
void setup(ClayControlUnit* w) {
	myDisplay.begin(w);
	myClock.begin(w);
	myKeypad.begin(w);
	myMainSwitch.begin(w);
	myMemory.begin();
	myMoisture.begin(w);
	myValveGroup.begin(w);
	myDebugger.begin(w);

	for(int8_t i = 0; i < VALVE_NUM; i++) {
		myValveGroup.setDays(i, myMemory.readEtvDays(i));
		myValveGroup.setMinOn(i, myMemory.readEtvMinOn(i));
	}

	MyTime tStart = myMemory.readStartTime();
	autoCycle.begin(tStart);

	pageSelector.begin();
}

void loop();

int main(int argc, char* argv[]) {
	ClayControlUnit w;
	bool finished = false;

	setup(&w);

	bool* pfinished = &finished;
	thread thread([pfinished] {
		while(!*pfinished) {
			loop();
			sleep_for(microseconds(10));
		}
	});

	w.show();
	finished = true;
	thread.join();

	return 0;
}
#else
#	error "No setup() definition"
#endif

void loop() {
	pageSelector.show();

	pageSelector.exec();

	autoCycle.exec();
}
