#ifndef CODE_INO
#define CODE_INO

#include "lib/Config.h"

#include "lib/Keypad.cpp"
//#include "lib/Debugger.cpp"
#include "lib/Display.cpp"
#include "lib/Clock.cpp"
#include "lib/MyTime.cpp"
#include "lib/MyString.cpp"
#include "lib/Valve.cpp"
#include "lib/PageSelector.cpp"
#include "lib/AutoCycle.cpp"

Keypad* myKeypad;
//Debugger* myDebugger;
Display* myDisplay;
Clock* myClock;
Valve* myEtv1;
Valve* myEtv2;
Valve* myEtv3;
Valve* myEtv4;
Valve* myEtv5;
Valve* myEtv6;
/*Valve* myEtv7;
Valve* myEtv8;
Valve* myEtv9;*/
Valve* myEtv[] = {nullptr, myEtv1, myEtv2, myEtv3, myEtv4, myEtv5, myEtv6/*, myEtv7, myEtv8, myEtv9*/};
int etvNum = sizeof(myEtv)/sizeof(myEtv[1]) -1;
PageSelector* pageSelector;
AutoCycle* autoCycle;

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

    myEtv[1] = new QtValve(w, myClock, 1, 0, 0);
    myEtv[2] = new QtValve(w, myClock, 2, 0, 0);
    myEtv[3] = new QtValve(w, myClock, 3, 0, 0);
    myEtv[4] = new QtValve(w, myClock, 4, 0, 0);
    myEtv[5] = new QtValve(w, myClock, 5, 0, 0);
    myEtv[6] = new QtValve(w, myClock, 6, 0, 0);
    myEtv[7] = new QtValve(w, myClock, 7, 0, 0);
    myEtv[8] = new QtValve(w, myClock, 8, 0, 0);
    myEtv[9] = new QtValve(w, myClock, 9, 0, 0);

    w->setKeypad(myKeypad);

    autoCycle = new AutoCycle(myKeypad, myDebugger, myDisplay, myClock, myEtv, etvNum);
    pageSelector = new PageSelector(myKeypad, myDebugger, myDisplay, myClock, myEtv, autoCycle);

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
#define lcdAddress 0x27
#define lcdLength 16
#define lcdHeight 2

//Etv
const int etvsPin[] = {-1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

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
//const int humidityPin = A7;
//endregion PINS

void setup() {
    
    myKeypad = new HwKeypad(cancelPin, downPin, upPin, confirmPin);
    //myDebugger = new HwDebugger(9600);
    
    myDisplay = new HwDisplay(lcdAddress, lcdLength, lcdHeight);
    myClock = new HwClock(rtcRst, rtcData, rtcClk);
    
    myEtv[1] = new HwValve(myClock, etvsPin[1], 0, 0);
    myEtv[2] = new HwValve(myClock, etvsPin[2], 0, 0);
    myEtv[3] = new HwValve(myClock, etvsPin[3], 0, 0);
    myEtv[4] = new HwValve(myClock, etvsPin[4], 0, 0);
    myEtv[5] = new HwValve(myClock, etvsPin[5], 0, 0);
    myEtv[6] = new HwValve(myClock, etvsPin[6], 0, 0);
    /*
    myEtv[7] = new HwValve(myClock, etvsPin[7], 0, 0);
    myEtv[8] = new HwValve(myClock, etvsPin[8], 0, 0);
    myEtv[9] = new HwValve(myClock, etvsPin[9], 0, 0);
    */

    autoCycle = new AutoCycle(myKeypad/*, myDebugger*/, myDisplay, myClock, myEtv, etvNum);

    pageSelector = new PageSelector(myKeypad/*, myDebugger*/, myDisplay, myClock, myEtv, autoCycle);
}
#endif
//endregion

void loop() {

    pageSelector->show();

    pageSelector->exec();

    autoCycle->exec();

}

#endif
