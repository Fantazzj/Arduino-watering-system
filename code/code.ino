#ifndef CODE_INO
#define CODE_INO

#include "lib/Config.h"
#include "lib/Keypad.cpp"
#include "lib/Display.cpp"
#include "lib/Clock.cpp"
#include "lib/MyTime.cpp"
#include "lib/MyString.cpp"
#include "lib/Valve.cpp"
#include "lib/Moisture.cpp"
#include "lib/PageSelector.cpp"
#include "lib/AutoCycle.cpp"

Keypad* myKeypad;
Display* myDisplay;
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
int8_t etvNum = sizeof(myEtv)/sizeof(myEtv[1]) -1;
Moisture* myMoisture;
PageSelector* pageSelector;
AutoCycle* autoCycle;

//region QTDESKTOP
#ifdef QTDESKTOP

#include "lib/ControlUnit.h"
#include "lib/qt-lib/QtKeypad.cpp"
#include "lib/qt-lib/QtDisplay.cpp"
#include "lib/qt-lib/QtClock.cpp"
#include "lib/qt-lib/QtValve.cpp"
#include "lib/qt-lib/QtMoisture.cpp"

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

    myMoisture = new QtMoisture(w);

    w->setKeypad(myKeypad);

    autoCycle = new AutoCycle(myClock, myEtv, etvNum);
    pageSelector = new PageSelector(myKeypad, myDisplay, myClock, myEtv, autoCycle);

}

#endif
//endregion

//region HWARDUINO
#ifdef HWARDUINO
#include "lib/hw-lib/HwKeypad.cpp"
#include "lib/hw-lib/HwDebugger.cpp"
#include "lib/hw-lib/HwDisplay.cpp"
#include "lib/hw-lib/HwClock.cpp"
#include "lib/hw-lib/HwValve.cpp"
#include "lib/hw-lib/HwMoisture.cpp"

//region PINS
//Display
#define lcdAddress 0x27
#define lcdLength 16
#define lcdHeight 2

//Etv
const int8_t etvsPin[] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

//Buttons
#define cancelPin A3
#define downPin A1
#define upPin A2
#define confirmPin A0

//RTC
#define rtcRst 10
#define rtcData 11
#define rtcClk 12

//Sensors
#define humidityPin A7
//endregion PINS

void setup() {
    
    myClock = new HwClock(rtcRst, rtcData, rtcClk);

    myEtv[1] = new HwValve(myClock, 1, 0, etvsPin[1]);
    myEtv[2] = new HwValve(myClock, 1, 0, etvsPin[2]);
    myEtv[3] = new HwValve(myClock, 1, 0, etvsPin[3]);
    myEtv[4] = new HwValve(myClock, 1, 0, etvsPin[4]);
    myEtv[5] = new HwValve(myClock, 1, 0, etvsPin[5]);
    myEtv[6] = new HwValve(myClock, 1, 0, etvsPin[6]);
    myEtv[7] = new HwValve(myClock, 1, 0, etvsPin[7]);
    myEtv[8] = new HwValve(myClock, 1, 0, etvsPin[8]);
    myEtv[9] = new HwValve(myClock, 1, 0, etvsPin[9]);
    
    myKeypad = new HwKeypad(cancelPin, downPin, upPin, confirmPin);

    myDisplay = new HwDisplay(lcdAddress, lcdLength, lcdHeight);

    myMoisture = new HwMoisture(humidityPin);

    autoCycle = new AutoCycle(myClock, myEtv, etvNum);

    pageSelector = new PageSelector(myKeypad, myDisplay, myClock, myEtv, autoCycle);
}
#endif
//endregion

void loop() {

    pageSelector->show();

    pageSelector->exec();

    autoCycle->exec();

}

#endif
