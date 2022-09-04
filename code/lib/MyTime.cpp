#ifndef MY_TIME_CPP
#define MY_TIME_CPP

enum Dow : uint8_t {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum Month : uint8_t {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class MyTime{
public:
    uint8_t hour = 15;
    uint8_t min = 50;
    uint8_t sec = 12;
    uint8_t date = 29;
    uint8_t mon = July;
    uint16_t year = 2022;
    uint8_t dow = Friday;

    static bool isDifferent(MyTime t1, MyTime t2) {
        if(t1.dow != t2.dow) return true;
        else if(t1.min != t2.min) return true;
        else if(t1.hour != t2.hour) return true;
        //else if(t1.sec != t2.sec) return true;
        else if(t1.date != t2.date) return true;
        else if(t1.mon != t2.mon) return true;
        else if(t1.year != t2.year) return true;
        else return false;
    }

    static bool isEqual(MyTime t1, MyTime t2) {
        if(t1.dow == t2.dow) return true;
        else if(t1.min == t2.min) return true;
        else if(t1.hour == t2.hour) return true;
        //else if(t1.sec == t2.sec) return true;
        else if(t1.date == t2.date) return true;
        else if(t1.mon == t2.mon) return true;
        else if(t1.year == t2.year) return true;
        else return false;
    }

    static bool timeIsNextOrEq(MyTime t1, MyTime t2) {
        if(t1.hour > t2.hour) return true;
        else if(t1.hour == t2.hour) {
            if(t1.min > t2.min) return true;
            else if(t1.min == t2.min) {
                if(t1.sec >= t2.sec) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }

    static int8_t elapsedHours(MyTime t1, MyTime t2) { //Only for <=24h
        int8_t hours;

        hours = t2.hour - t1.hour;
        if(hours < 0) hours+=24;

        return hours;
    }

    static int8_t elapsedMin(MyTime t1, MyTime t2) {
        int8_t hoursMin;
        int8_t minutes;

        hoursMin = elapsedHours(t1, t2) * 60;

        minutes = t2.min - t1.min;
        if(minutes < 0) minutes+=60;

        return minutes + hoursMin;
    }

    static int8_t elapsedSec(MyTime t1, MyTime t2) {
        int8_t minutesSec;
        int8_t seconds;

        minutesSec = elapsedMin(t1, t2) * 60;

        seconds = t2.sec - t1.sec;
        if(seconds < 0) seconds+=60;

        return seconds + minutesSec;
    }

    #ifdef HWARDUINO
    static int8_t freeze(unsigned long ms) {
        delay(ms);
    }
    #endif
    #ifdef QTDESKTOP
    static int8_t freeze(unsigned long ms) {}
    #endif

};

#endif //MY_TIME_CPP
