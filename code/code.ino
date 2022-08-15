#include "lib/Config.h"

#ifndef CODE_INO
#define CODE_INO

#include "lib/Keypad.cpp"
#include "lib/Debugger.cpp"
#include "lib/Display.cpp"
#include "lib/Clock.cpp"
#include "lib/MyTime.cpp"
#include "lib/MyString.cpp"
#include "lib/Valve.cpp"
#include "lib/PageSelector.cpp"

Keypad* myKeypad;
Debugger* myDebugger;
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
PageSelector* pageSelector;

//region QTDESKTOP
#ifdef QTDESKTOP

#include "lib/ControlUnit.h"
#include "lib/qt-lib/QtKeypad.cpp"
#include "lib/qt-lib/QtDebugger.cpp"
#include "lib/qt-lib/QtDisplay.cpp"
#include "lib/qt-lib/QtClock.cpp"
#include "lib/qt-lib/QtValve.cpp"

void setup(ControlUnit* w) {

    myKeypad = new QtKeypad();
    myDebugger = new QtDebugger(w);
    myDisplay = new QtDisplay(w, 16, 2);
    myClock = new QtClock(w);

    myEtv[1] = new QtValve(w, myClock, 1, 5, 1);
    myEtv[2] = new QtValve(w, myClock, 2, 5, 1);
    myEtv[3] = new QtValve(w, myClock, 3, 5, 1);
    myEtv[4] = new QtValve(w, myClock, 4, 5, 1);
    myEtv[5] = new QtValve(w, myClock, 5, 5, 1);
    myEtv[6] = new QtValve(w, myClock, 6, 5, 1);
    myEtv[7] = new QtValve(w, myClock, 7, 5, 1);
    myEtv[8] = new QtValve(w, myClock, 8, 5, 1);
    myEtv[9] = new QtValve(w, myClock, 9, 5, 1);

    w->setKeypad(myKeypad);

    pageSelector = new PageSelector(myKeypad, myDebugger, myDisplay, myClock, myEtv);

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

//region PINS
//Display
const int lcdAddress = 0x27;
const int lcdLength = 16;
const int lcdHeight = 2;

//Etv
const int etvsPin[] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

//Buttons
const int cancelPin = A0;
const int downPin = A2;
const int upPin = A1;
const int confirmPin = A3;

//RTC
const int rtcRst = 10;
const int rtcData = 11;
const int rtcClk = 12;

//Sensors
//const int humidityPin = A7;
//endregion PINS

void setup() {
    
    myKeypad = new HwKeypad(cancelPin, downPin, upPin, confirmPin);
    myDebugger = new HwDebugger(9600);
    
    myDisplay = new HwDisplay(lcdAddress, lcdLength, lcdHeight);
    myClock = new HwClock(rtcRst, rtcData, rtcClk);
    
    myEtv[1] = new HwValve(myClock, etvsPin[1], 1, 1);
    myEtv[2] = new HwValve(myClock, etvsPin[2], 1, 1);
    myEtv[3] = new HwValve(myClock, etvsPin[3], 1, 1);
    myEtv[4] = new HwValve(myClock, etvsPin[4], 1, 1);
    myEtv[5] = new HwValve(myClock, etvsPin[5], 1, 1);
    myEtv[6] = new HwValve(myClock, etvsPin[6], 1, 1);
    myEtv[7] = new HwValve(myClock, etvsPin[7], 1, 1);
    myEtv[8] = new HwValve(myClock, etvsPin[8], 1, 1);
    myEtv[9] = new HwValve(myClock, etvsPin[9], 1, 1);

    pageSelector = new PageSelector(myKeypad, myDebugger, myDisplay, myClock, myEtv);
    
}
#endif
//endregion

void loop() {

    pageSelector->show();

    pageSelector->exec();

}

#endif
