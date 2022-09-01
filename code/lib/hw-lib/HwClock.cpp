#ifndef HWCLOCK_CPP
#define HWCLOCK_CPP

#include "../Clock.cpp"
/*
#include "../../src/DS1302.h"

class HwClock: public Clock {
private:
    DS1302* rtc;

public:
    HwClock(int rtcRst, int rtcData, int rtcClk) {
        rtc = new DS1302(rtcRst, rtcData, rtcClk);
    }

    MyTime getTime() {
        Time now;
        MyTime time;
        now = rtc->getTime();

        time.date = now.date;
        time.dow = now.dow;
        time.hour = now.hour;
        time.min = now.min;
        time.mon = now.mon;
        time.sec = now.sec;
        time.year = now.sec;

        return time;
    }

    void setTime(MyTime time) {
        rtc->setTime(time.hour, time.min, 00);
        rtc->setDate(time.date, time.mon, time.year);
        rtc->setDOW(time.dow);
    }

protected:
};
*/

class HwClock: public Clock {
private:
    MyTime t;
    int prevMillis=0;

public:
    HwClock(int rtcRst, int rtcData, int rtcClk) {
        t.date = 10;
        t.mon = 8;
        t.year = 2022;

        char z = '0';
        t.hour = __TIME__[1]-z + (__TIME__[0]-z)*10;
        t.min = __TIME__[4]-z + (__TIME__[3]-z)*10;
        t.sec = __TIME__[7]-z + (__TIME__[6]-z)*10;

        t.dow = Wednesday;
    }
    MyTime getTime() {
        int elapMillis = millis();

        t.sec += (elapMillis - prevMillis)/1000;
        t.min += t.sec/60;
        t.hour += t.min/60;
        t.date += t.hour/24;

        t.sec %= 60;
        t.min %=60;
        t.hour %= 24;

        if(elapMillis-prevMillis >= 1000)
            prevMillis = elapMillis;

        return t;
    }
    void setTime(MyTime timeIn) {
        t.date = timeIn.date;
        t.mon = timeIn.mon;
        t.year = timeIn.year;
        t.hour = timeIn.hour;
        t.min = timeIn.min;
        t.sec = timeIn.sec;
        t.dow = timeIn.dow;
    }
};

#endif
