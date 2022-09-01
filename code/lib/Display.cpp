#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include "MyTime.cpp"
#include "MyString.cpp"

class Display {
private:

public:
    Display() = default;
    virtual void printSimpleText(char text[]) {}
    virtual void printData(char text1[], int data, char text2[]) {}
    virtual void printData(char text1[], int data1, char text2[], int data2, char text3[]) {}
    virtual void printIn(char text[], int x, int y) {}
    virtual void printIn(int data, int x, int y) {}
    virtual void showClock(MyTime timeIn) {}
    virtual void blinkAt(int x, int y) {}
    virtual void noBlink() {}
    virtual void clockSym() {}
    virtual void noClockSym() {}
    virtual void dropSym() {}
    virtual void noDropSym() {}
    virtual void checkSym() {}
    virtual void noCheckSym() {}
    virtual void noSymbols() {}

protected:
};

#endif
