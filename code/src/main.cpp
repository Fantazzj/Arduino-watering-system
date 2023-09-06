#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/Clock.hpp"
#include "../lib/core/Keypad.hpp"
#include "../lib/core/MainSwitch.hpp"
#include "../lib/core/Memory.hpp"
#include "../lib/core/Moisture.hpp"
#include "../lib/core/MyString.hpp"
#include "../lib/core/MyTime.hpp"
#include "../lib/core/PageSelector.hpp"
#include "../lib/core/UnitDisplay.hpp"
#include "../lib/core/Valve.hpp"

Keypad* myKeypad;
UnitDisplay* myDisplay;
Clock* myClock;
const int8_t etvNum = 9;
Valve* myEtv[etvNum + 1];
MainSwitch* myMainSwitch;
Memory* myMemory;
Moisture* myMoisture;
PageSelector* pageSelector;
AutoCycle* autoCycle;

#if defined(QTDESKTOP)

#	include "lib/qt-lib/ControlUnit.h"
#	include "lib/qt-lib/QtClock.hpp"
#	include "lib/qt-lib/QtDisplay.hpp"
#	include "lib/qt-lib/QtKeypad.hpp"
#	include "lib/qt-lib/QtMainSwitch.hpp"
#	include "lib/qt-lib/QtMemory.hpp"
#	include "lib/qt-lib/QtMoisture.hpp"
#	include "lib/qt-lib/QtValve.hpp"

#	include <QApplication>
#	include <QThread>

void setup(ControlUnit* w) {
	myKeypad = new QtKeypad();
	myDisplay = new QtDisplay(w, 16, 2);
	myClock = new QtClock(w);

	myMainSwitch = new QtMainSwitch(w);

	myEtv[1] = new QtValve(myClock, 5, 0, w, 1);
	myEtv[2] = new QtValve(myClock, 5, 0, w, 2);
	myEtv[3] = new QtValve(myClock, 5, 0, w, 3);
	myEtv[4] = new QtValve(myClock, 5, 0, w, 4);
	myEtv[5] = new QtValve(myClock, 5, 0, w, 5);
	myEtv[6] = new QtValve(myClock, 5, 0, w, 6);
	myEtv[7] = new QtValve(myClock, 5, 0, w, 7);
	myEtv[8] = new QtValve(myClock, 5, 0, w, 8);
	myEtv[9] = new QtValve(myClock, 5, 0, w, 9);

	myMemory = new QtMemory(etvNum);
	for(int8_t i = 1; i <= etvNum; i++) {
		myEtv[i]->minOn = myMemory->readEtvMinOn(i);
		myEtv[i]->days = myMemory->readEtvDays(i);
	}

	myMoisture = new QtMoisture(w);

	w->setKeypad(myKeypad);

	MyTime tStart = myMemory->readStartTime();
	autoCycle = new AutoCycle(myClock, myEtv, etvNum, myMainSwitch, myMoisture, tStart);
	pageSelector = new PageSelector(myKeypad, myDisplay, myClock, myEtv, myMainSwitch, myMemory, autoCycle);
}

void loop();

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	ControlUnit w;

	setup(&w);

	QThread* thread = QThread::create([] {
		while(true) {
			loop();
			QThread::usleep(1);
		}
	});
	thread->start();

	w.show();
	return a.exec();
}

#elif defined(HWARDUINO)

#	include "../lib/arduino-lib/HwClock.hpp"
#	include "../lib/arduino-lib/HwDisplay.hpp"
#	include "../lib/arduino-lib/HwKeypad.hpp"
#	include "../lib/arduino-lib/HwMainSwitch.hpp"
#	include "../lib/arduino-lib/HwMemory.hpp"
#	include "../lib/arduino-lib/HwMoisture.hpp"
#	include "../lib/arduino-lib/HwValve.hpp"

//UnitDisplay
#	define lcdAddress 0x27
#	define lcdLength 16
#	define lcdHeight 2

//Etv
const int8_t etvsPin[] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
#	define mainSwitchPin 1

//Buttons
#	define cancelPin A3
#	define downPin A1
#	define upPin A2
#	define confirmPin A0

//Sensors
#	define humidityPin A7

void setup() {
	myClock = new HwClock();

	myMainSwitch = new HwMainSwitch(mainSwitchPin);

	myEtv[1] = new HwValve(myClock, 1, 0, etvsPin[1]);
	myEtv[2] = new HwValve(myClock, 1, 0, etvsPin[2]);
	myEtv[3] = new HwValve(myClock, 1, 0, etvsPin[3]);
	myEtv[4] = new HwValve(myClock, 1, 0, etvsPin[4]);
	myEtv[5] = new HwValve(myClock, 1, 0, etvsPin[5]);
	myEtv[6] = new HwValve(myClock, 1, 0, etvsPin[6]);
	myEtv[7] = new HwValve(myClock, 1, 0, etvsPin[7]);
	myEtv[8] = new HwValve(myClock, 1, 0, etvsPin[8]);
	myEtv[9] = new HwValve(myClock, 1, 0, etvsPin[9]);

	myMemory = new HwMemory(etvNum);
	for(int8_t i = 1; i <= etvNum; i++) {
		myEtv[i]->minOn = myMemory->readEtvMinOn(i);
		myEtv[i]->days = myMemory->readEtvDays(i);
	}
	MyTime tStart = myMemory->readStartTime();

	myKeypad = new HwKeypad(cancelPin, downPin, upPin, confirmPin);

	myDisplay = new HwDisplay(lcdAddress, lcdLength, lcdHeight);

	myMoisture = new HwMoisture(humidityPin);

	autoCycle = new AutoCycle(myClock, myEtv, etvNum, myMainSwitch, myMoisture, tStart);

	pageSelector = new PageSelector(myKeypad, myDisplay, myClock, myEtv, myMainSwitch, myMemory, autoCycle);
}

#else
#	error Missing setup() definition

#endif

void loop() {
	pageSelector->show();

	pageSelector->exec();

	autoCycle->exec();
}
