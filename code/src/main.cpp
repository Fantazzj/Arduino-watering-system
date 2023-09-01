#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/Clock.hpp"
#include "../lib/core/Keypad.hpp"
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
Valve* myEtv1;
Valve* myEtv2;
Valve* myEtv3;
Valve* myEtv4;
Valve* myEtv5;
Valve* myEtv6;
Valve* myEtv7;
Valve* myEtv8;
Valve* myEtv9;
Valve* myEtv[] = {nullptr, myEtv1, myEtv2, myEtv3, myEtv4, myEtv5, myEtv6, myEtv7, myEtv8, myEtv9};
Memory* myMemory;
int8_t etvNum = sizeof(myEtv) / sizeof(myEtv[1]) - 1;
Moisture* myMoisture;
PageSelector* pageSelector;
AutoCycle* autoCycle;

#ifdef QTDESKTOP

#	include "lib/qt-lib/ControlUnit.h"
#	include "lib/qt-lib/QtClock.hpp"
#	include "lib/qt-lib/QtDisplay.hpp"
#	include "lib/qt-lib/QtKeypad.hpp"
#	include "lib/qt-lib/QtMemory.hpp"
#	include "lib/qt-lib/QtMoisture.hpp"
#	include "lib/qt-lib/QtValve.hpp"

#	include <QApplication>
#	include <QThread>
#	include <thread>

void setup(ControlUnit* w) {
	myKeypad = new QtKeypad();
	myDisplay = new QtDisplay(w, 16, 2);
	myClock = new QtClock(w);

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
	autoCycle = new AutoCycle(myClock, myEtv, etvNum, myMoisture, tStart);
	pageSelector = new PageSelector(myKeypad, myDisplay, myClock, myEtv, myMemory, autoCycle);
}

void loop();

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	ControlUnit w;

	setup(&w);

	QThread* thread = QThread::create([] {
		while(true) {
			loop();
			std::this_thread::sleep_for(std::chrono::nanoseconds(100));
		}
	});
	thread->start();

	w.show();
	return a.exec();
}

#endif

#ifdef HWARDUINO

#	include "../lib/arduino-lib/HwClock.hpp"
#	include "../lib/arduino-lib/HwDisplay.hpp"
#	include "../lib/arduino-lib/HwKeypad.hpp"
#	include "../lib/arduino-lib/HwMemory.hpp"
#	include "../lib/arduino-lib/HwMoisture.hpp"
#	include "../lib/arduino-lib/HwValve.hpp"

//UnitDisplay
#	define lcdAddress 0x27
#	define lcdLength 16
#	define lcdHeight 2

//Etv
const int8_t etvsPin[] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

//Buttons
#	define cancelPin A3
#	define downPin A1
#	define upPin A2
#	define confirmPin A0

//RTC
//#	define rtcRst 10
//#	define rtcData 11
//#	define rtcClk 12

//Sensors
#	define humidityPin A7

void setup() {
	myClock = new HwClock();

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

	autoCycle = new AutoCycle(myClock, myEtv, etvNum, myMoisture, tStart);

	pageSelector = new PageSelector(myKeypad, myDisplay, myClock, myEtv, myMemory, autoCycle);
}

#endif

void loop() {
	pageSelector->show();

	pageSelector->exec();

	autoCycle->exec();
}
