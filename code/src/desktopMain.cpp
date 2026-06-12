#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/PageSelector.hpp"
#include "../lib/desktop-clay/ClayClock.hpp"
#include "../lib/desktop-clay/ClayControlUnit.hpp"
#include "../lib/desktop-clay/ClayDebugger.hpp"
#include "../lib/desktop-clay/ClayDisplay.hpp"
#include "../lib/desktop-clay/ClayKeypad.hpp"
#include "../lib/desktop-clay/ClayMainSwitch.hpp"
#include "../lib/desktop-clay/ClayMemory.hpp"
#include "../lib/desktop-clay/ClayMoisture.hpp"
#include "../lib/desktop-clay/ClayTimer.hpp"
#include "../lib/desktop-clay/ClayValveGroup.hpp"

#include <chrono>
#include <thread>

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
