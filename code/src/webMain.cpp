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
#include <emscripten/html5.h>
#include <thread>

using std::thread;
using std::chrono::microseconds;
using std::this_thread::sleep_for;

ClayControlUnit window;

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

void watering_loop() {
	pageSelector.show();
	pageSelector.exec();
	autoCycle.exec();
}

void ui_loop() {
	window.show();

	watering_loop();
}

int main() {
	myDisplay.begin(&window);
	myClock.begin(&window);
	myKeypad.begin(&window);
	myMainSwitch.begin(&window);
	myMemory.begin();
	myMoisture.begin(&window);
	myValveGroup.begin(&window);
	myDebugger.begin(&window);
	for(int8_t i = 0; i < VALVE_NUM; i++) {
		myValveGroup.setDays(i, myMemory.readEtvDays(i));
		myValveGroup.setMinOn(i, myMemory.readEtvMinOn(i));
	}

	MyTime tStart = myMemory.readStartTime();
	autoCycle.begin(tStart);
	pageSelector.begin();

	emscripten_set_main_loop(ui_loop, 0, true);
}
