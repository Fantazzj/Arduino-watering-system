#include "../lib/core/AutoCycle.hpp"
#include "../lib/core/PageSelector.hpp"

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
QtValve* myEtv[etvNum];
QtMainSwitch myMainSwitch;
QtMemory myMemory(etvNum);
QtMoisture myMoisture;

AutoCycle autoCycle(myClock, (Valve**) myEtv, etvNum, myMainSwitch, myMoisture);
PageSelector pageSelector(myKeypad, myDisplay, myClock, (Valve**) myEtv, myMainSwitch, myMemory, autoCycle);

void setup(ControlUnit* w) {
	myDisplay.begin(w);
	myClock.begin(w);
	myMainSwitch.begin(w);
	myMemory.begin();
	myMoisture.begin(w);

	for(int8_t i = 0; i < etvNum; i++) {
		myEtv[i] = new QtValve(myClock, i);
		myEtv[i]->begin(w);
		myEtv[i]->minOn = myMemory.readEtvMinOn(i);
		myEtv[i]->days = myMemory.readEtvDays(i);
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
	int exit = a.exec();

	for(int8_t i = 0; i < etvNum; i++)
		delete myEtv[i];

	return exit;
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
const int8_t etvsPin[] = {6, 7, 2, 3, 4, 5, 8, 9, 10};
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
HwValve* myEtv[etvNum];
HwMainSwitch myMainSwitch(mainSwitchPin);
HwMemory myMemory(etvNum);
HwMoisture myMoisture(humidityPin);

AutoCycle autoCycle(myClock, (Valve**) myEtv, etvNum, myMainSwitch, myMoisture);
PageSelector pageSelector(myKeypad, myDisplay, myClock, (Valve**) myEtv, myMainSwitch, myMemory, autoCycle);

void setup() {

#	if DEBUG
	mySerial = &Serial;
	mySerial->begin(9600);
#	endif

	myDisplay.begin();
	myClock.begin();
	myMainSwitch.begin();
	myMemory.begin();

	for(int8_t i = 0; i < etvNum; i++) {
		myEtv[i] = new HwValve(myClock, etvsPin[i]);
		myEtv[i]->begin();
		myEtv[i]->minOn = myMemory.readEtvMinOn(i);
		myEtv[i]->days = myMemory.readEtvDays(i);
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
