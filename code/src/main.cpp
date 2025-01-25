#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/Clock.hpp"
#include "../lib/core/Keypad.hpp"
#include "../lib/core/MainSwitch.hpp"
#include "../lib/core/Memory.hpp"
#include "../lib/core/Moisture.hpp"
#include "../lib/core/PageSelector.hpp"
#include "../lib/core/UnitDisplay.hpp"
#include "../lib/core/Valve.hpp"
#include "../lib/date-time/MyTime.hpp"

#if defined(QTDESKTOP)

#	include "../lib/qt-lib/ControlUnit.h"
#	include "../lib/qt-lib/QtClock.hpp"
#	include "../lib/qt-lib/QtDisplay.hpp"
#	include "../lib/qt-lib/QtKeypad.hpp"
#	include "../lib/qt-lib/QtMainSwitch.hpp"
#	include "../lib/qt-lib/QtMemory.hpp"
#	include "../lib/qt-lib/QtMoisture.hpp"
#	include "../lib/qt-lib/QtValve.hpp"

#	include <QApplication>
#	include <QThread>

QtKeypad myKeypad;
QtDisplay myDisplay;
QtClock myClock;
const int8_t etvNum = 9;
Valve* myEtv[etvNum];
QtMainSwitch myMainSwitch;
QtMemory myMemory(etvNum);
QtMoisture myMoisture;

AutoCycle autoCycle(myClock, myEtv, etvNum, myMainSwitch, myMoisture);
PageSelector pageSelector(myKeypad, myDisplay, myClock, myEtv, myMainSwitch, myMemory, autoCycle);

void setup(ControlUnit* w) {
	myDisplay.begin(w);
	myClock.begin(w);
	myMainSwitch.begin(w);
	myMemory.begin();
	myMoisture.begin(w);

	for(int8_t i = 0; i < etvNum; i++) {
		uint8_t minOn = myMemory.readEtvMinOn(i);
		uint8_t days = myMemory.readEtvDays(i);
		myEtv[i] = new QtValve(myClock, minOn, days, w, i);
	}
	MyTime tStart = myMemory.readStartTime();

	autoCycle.begin(tStart);
	pageSelector.begin();
}

void loop();

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	ControlUnit w;

	w.setKeypad(&myKeypad);
	setup(&w);

	QThread* thread = QThread::create([] {
		Q_FOREVER {
			loop();
			QThread::usleep(10);
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
const int8_t etvsPin[] = {-1, 6, 7, 2, 3, 4, 5, 8, 9, 10};
#	define mainSwitchPin 11

//Buttons
#	define cancelPin A3
#	define downPin A1
#	define upPin A2
#	define confirmPin A0

#	define DEBUG 1
#	if DEBUG
#		warning Debug mode on
#		include <SoftwareSerial.h>
HardwareSerial* mySerial;
#	endif

//Sensors
#	define humidityPin A7

HwKeypad myKeypad(cancelPin, downPin, upPin, confirmPin);
HwDisplay myDisplay(lcdAddress, lcdLength, lcdHeight);
HwClock myClock;
const int8_t etvNum = 9;
Valve* myEtv[etvNum + 1];
HwMainSwitch myMainSwitch(mainSwitchPin);
HwMemory myMemory(etvNum);
HwMoisture myMoisture(humidityPin);

AutoCycle autoCycle(myClock, myEtv, etvNum, myMainSwitch, myMoisture);
PageSelector pageSelector(myKeypad, myDisplay, myClock, myEtv, myMainSwitch, myMemory, autoCycle);

void setup() {

#	if DEBUG
	mySerial = &Serial;
	mySerial->begin(9600);
#	endif

	myDisplay.begin();
	myClock.begin();
	myMainSwitch.begin();
	myMemory.begin();

	myEtv[0] = nullptr;
	for(int8_t i = 1; i < etvNum + 1; i++) {
		uint8_t minOn = myMemory.readEtvMinOn(i);
		uint8_t days = myMemory.readEtvDays(i);
		myEtv[i] = new HwValve(myClock, minOn, days, etvsPin[i]);
	}

	MyTime tStart = myMemory.readStartTime();

	autoCycle.begin(tStart);
	pageSelector.begin();
}

#else
#	error Missing setup() definition

#endif

void loop() {
	pageSelector.show();

	pageSelector.exec();

	autoCycle.exec();
}
