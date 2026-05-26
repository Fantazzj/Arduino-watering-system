#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/PageSelector.hpp"
#include "../lib/hardware-arduino/HwClock.hpp"
#include "../lib/hardware-arduino/HwDebugger.hpp"
#include "../lib/hardware-arduino/HwDisplay.hpp"
#include "../lib/hardware-arduino/HwKeypad.hpp"
#include "../lib/hardware-arduino/HwMainSwitch.hpp"
#include "../lib/hardware-arduino/HwMemory.hpp"
#include "../lib/hardware-arduino/HwMoisture.hpp"
#include "../lib/hardware-arduino/HwTimer.hpp"
#include "../lib/hardware-arduino/HwValveGroup.hpp"

//UnitDisplay
#define lcdAddress 0x27
#define lcdLength 16
#define lcdHeight 2

//Etv
constexpr int8_t etvsPin[] = {6, 7, 2, 3, 4, 5, 8, 9, 10};
#define mainSwitchPin 11

//Buttons
#define cancelPin A3
#define downPin A1
#define upPin A2
#define confirmPin A0

//Sensors
#define humidityPin A7

//Serial
#define baud 115200

HwKeypad myKeypad(cancelPin, downPin, upPin, confirmPin);
HwDisplay myDisplay(lcdAddress, lcdLength, lcdHeight);
HwClock myClock;
HwValveGroup myValveGroup(myClock, etvsPin);
HwMainSwitch myMainSwitch(mainSwitchPin);
HwMemory myMemory;
HwMoisture myMoisture(humidityPin);
HwDebugger myDebugger;
HwTimer myTimer;

AutoCycle autoCycle(myClock, myValveGroup, myMainSwitch, myMoisture, myTimer, myDebugger);
PageSelector pageSelector(myKeypad, myDisplay, myClock, myValveGroup, myMainSwitch, myMemory, myTimer, myDebugger, autoCycle);

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

	const MyTime tStart = myMemory.readStartTime();

	autoCycle.begin(tStart);
	pageSelector.begin();
}

void loop() {
	pageSelector.show();

	pageSelector.exec();

	autoCycle.exec();
}
