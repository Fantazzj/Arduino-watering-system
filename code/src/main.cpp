#include "../lib/core-lib/AutoCycle.hpp"
#include "../lib/core-lib/PageSelector.hpp"

#if defined(QTDESKTOP)
#	include "../lib/qt-lib/ControlUnit.h"
#	include "../lib/qt-lib/QtClock.hpp"
#	include "../lib/qt-lib/QtDisplay.hpp"
#	include "../lib/qt-lib/QtKeypad.hpp"
#	include "../lib/qt-lib/QtMainSwitch.hpp"
#	include "../lib/qt-lib/QtMemory.hpp"
#	include "../lib/qt-lib/QtMoisture.hpp"
#	include "../lib/qt-lib/QtValveGroup.hpp"
#	include "../lib/qt-lib/QtDebugger.hpp"
#	include "../lib/qt-lib/QtTimer.hpp"

#	include <QApplication>
#	include <QThread>

QtKeypad myKeypad;
QtDisplay myDisplay;
QtClock myClock;
QtValveGroup myValveGroup(myClock);
QtMainSwitch myMainSwitch;
QtMemory myMemory(VALVE_NUM);
QtMoisture myMoisture;
QtDebugger myDebugger;
QtTimer myTimer;

#elif defined(HWARDUINO)
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
#else
#	error "No variable definition"
#endif

AutoCycle autoCycle(myClock, myValveGroup, VALVE_NUM, myMainSwitch, myMoisture, myTimer);
PageSelector pageSelector(myKeypad, myDisplay, myClock, myValveGroup, myMainSwitch, myMemory, myTimer, autoCycle);

#if defined(QTDESKTOP)
void setup(ControlUnit* w) {
	myDisplay.begin(w);
	myClock.begin(w);
	myMainSwitch.begin(w);
	myMemory.begin();
	myMoisture.begin(w);
	myValveGroup.begin(w);

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

	return exit;
}
#elif defined(HWARDUINO)
void setup() {
	myDisplay.begin();
	myClock.begin();
	myMainSwitch.begin();
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

#	include "../lib/clay-lib/ClayControlUnit.hpp"

/*
void setup(ControlUnit* w) {
	myDisplay.begin(w);
	myClock.begin(w);
	myMainSwitch.begin(w);
	myMemory.begin();
	myMoisture.begin(w);
	myValveGroup.begin(w);

	for(int8_t i = 0; i < VALVE_NUM; i++) {
		myValveGroup.setDays(i, myMemory.readEtvDays(i));
		myValveGroup.setMinOn(i, myMemory.readEtvMinOn(i));
	}

	MyTime tStart = myMemory.readStartTime();
	autoCycle.begin(tStart);

	pageSelector.begin();
}
 */

void loop();

int main(int argc, char* argv[]) {
	ClayControlUnit w;

	//w.setKeypad(&myKeypad);
	//setup(&w);

	QThread* thread = QThread::create([] {
		for(;;) {
			loop();
			QThread::usleep(10);
		}
	});
	thread->start();

	w.show();
	int exit = a.exec();

	return exit;
}

#else
#	error "No setup() definition"
#endif

void loop() {
	pageSelector.show();

	pageSelector.exec();

	autoCycle.exec();
}
