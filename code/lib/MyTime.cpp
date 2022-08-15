#ifndef MY_TIME_CPP
#define MY_TIME_CPP

enum Dow : unsigned int {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum Month : unsigned int {
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
    int hour = 15;
    int min = 50;
    int sec = 12;
    int date = 29;
    int mon = July;
    int year = 2022;
    int dow = Friday;

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

    /*bool operator!=(const MyTime t1, const MyTime t2) {

    }*/

    static int elapsedHours(MyTime t1, MyTime t2) { //Only for <=24h
        int hours;

        hours = t2.hour - t1.hour;
        if(hours < 0) hours+=24;

        return hours;
    }

    static int elapsedMin(MyTime t1, MyTime t2) {
        int hoursMin;
        int minutes;

        hoursMin = elapsedHours(t1, t2) * 60;

        minutes = t2.min - t1.min;
        if(minutes < 0) minutes+=60;

        return minutes + hoursMin;
    }

    static int elapsedSec(MyTime t1, MyTime t2) {
        int minutesSec;
        int seconds;

        minutesSec = elapsedMin(t1, t2) * 60;

        seconds = t2.sec - t1.sec;
        if(seconds < 0) seconds+=60;

        return seconds + minutesSec;
    }

};

#endif //MY_TIME_CPP
