#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/PageSelector.hpp"
#include "../lib/desktop-clay/ClayControlUnit.hpp"
#include "../lib/desktop-clay/ClayValveGroup.hpp"
#include "../lib/desktop-clay/StdClock.hpp"
#include "../lib/desktop-clay/StdDebugger.hpp"
#include "../lib/desktop-clay/StdDisplay.hpp"
#include "../lib/desktop-clay/StdKeypad.hpp"
#include "../lib/desktop-clay/StdMainSwitch.hpp"
#include "../lib/desktop-clay/StdMemory.hpp"
#include "../lib/desktop-clay/StdMoisture.hpp"
#include "../lib/desktop-clay/StdTimer.hpp"

#include <chrono>
#include <thread>

using std::thread;
using std::chrono::microseconds;
using std::this_thread::sleep_for;

StdKeypad myKeypad;
StdDisplay myDisplay;
StdClock myClock;
ClayValveGroup myValveGroup(myClock);
StdMainSwitch myMainSwitch;
StdMemory myMemory("./memory.bin");
StdMoisture myMoisture;
StdDebugger myDebugger;
StdTimer myTimer;

AutoCycle autoCycle(myClock, myValveGroup, myMainSwitch, myMoisture, myTimer, myDebugger);
PageSelector pageSelector(myKeypad, myDisplay, myClock, myValveGroup, myMainSwitch, myMemory, myTimer, myDebugger, autoCycle);

ClayControlUnit unit(myDisplay, myClock, myKeypad, myValveGroup, myMainSwitch, myMoisture, myDebugger);

void setup() {
	for(int8_t i = 0; i < VALVE_NUM; i++) {
		myValveGroup.setDays(i, myMemory.readEtvDays(i));
		myValveGroup.setMinOn(i, myMemory.readEtvMinOn(i));
	}

	MyTime tStart = myMemory.readStartTime();
	autoCycle.begin(tStart);

	pageSelector.begin();
}

void loop() {
	pageSelector.show();

	pageSelector.exec();

	autoCycle.exec();
}

int main(int argc, char* argv[]) {
	bool finished = false;

	setup();

	bool* pfinished = &finished;
	thread thread([pfinished] {
		while(!*pfinished) {
			loop();
			sleep_for(microseconds(10));
		}
	});

	for(;;)
		unit.draw();
	finished = true;
	thread.join();

	return 0;
}
