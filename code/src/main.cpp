#include "../lib/core-lib/AutoCycle.hpp"
#include "../lib/core-lib/PageSelector.hpp"

#if defined(HWARDUINO)
#	include "../lib/arduino-lib/HwClock.hpp"
#	include "../lib/arduino-lib/HwDisplay.hpp"
#	include "../lib/arduino-lib/HwKeypad.hpp"
#	include "../lib/arduino-lib/HwMainSwitch.hpp"
#	include "../lib/arduino-lib/HwMemory.hpp"
#	include "../lib/arduino-lib/HwMoisture.hpp"
#	include "../lib/arduino-lib/HwValveGroup.hpp"
#	include "../lib/arduino-lib/HwDebugger.hpp"
#	include "../lib/arduino-lib/HwTimer.hpp"

//UnitDisplay
#	define lcdAddress 0x27
#	define lcdLength 16
#	define lcdHeight 2

//Etv
const int8_t etvsPin[] = {6, 7, 2, 3, 4, 5, 8, 9, 10};
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
HwMemory myMemory(VALVE_NUM);
HwMoisture myMoisture(humidityPin);
HwDebugger myDebugger;
HwTimer myTimer;
#elif defined(CLAYDESKTOP)
#	include "../lib/clay-lib/ClayControlUnit.hpp"
#	include "../lib/clay-lib/ClayClock.hpp"
#	include "../lib/clay-lib/ClayDisplay.hpp"
#	include "../lib/clay-lib/ClayKeypad.hpp"
#	include "../lib/clay-lib/ClayMainSwitch.hpp"
#	include "../lib/clay-lib/ClayMemory.hpp"
#	include "../lib/clay-lib/ClayMoisture.hpp"
#	include "../lib/clay-lib/ClayValveGroup.hpp"
#	include "../lib/clay-lib/ClayDebugger.hpp"
#	include "../lib/clay-lib/ClayTimer.hpp"

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

AutoCycle autoCycle(myClock, myValveGroup, VALVE_NUM, myMainSwitch, myMoisture, myTimer, myDebugger);
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
