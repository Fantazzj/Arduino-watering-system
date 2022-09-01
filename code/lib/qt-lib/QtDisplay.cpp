#ifndef QT_DISPLAY_CPP
#define QT_DISPLAY_CPP

#include "lib/Display.cpp"
#include "../ControlUnit.h"

class QtDisplay: public Display{
private:

    ControlUnit* w;

    int length;
    int height;
    int displayChars;

    void _displayError1() {
        w->printOnDisplay("Err. string");
        w->setCursorDisplay(0, 1);
        w->printOnDisplay("too big");
    }

    void _arrangeWords(QString text, QString rows[]) {
        QString buffer = "";
        int row = 0;

        if(!text.endsWith(' ')) text += " ";

        for(int i=0; i<text.length(); i++) {
            if(text.data()[i] != ' ') buffer += text.data()[i];
            else {
                if(rows[row].length() + buffer.length() <= length) rows[row] += (buffer + " ");
                else if(row+1 <= height) rows[++row] += (buffer + " ");
                buffer.clear();
            }
        }

    }

    void _printRows(QString rows[]) {
        for(int row=0; row < height; row++) {
            w->setCursorDisplay(0, row);
            w->printOnDisplay(rows[row]);
        }
    }

    QString _arrangeDate(MyTime time) {
        QString arrangedDate = "";
        QString separator = "/";
        if(time.date < 10) arrangedDate += "0";
        arrangedDate += QString::number(time.date);
        arrangedDate += separator;
        if(time.mon < 10) arrangedDate += "0";
        arrangedDate += QString::number(time.mon);
        arrangedDate += separator;
        arrangedDate += QString::number(time.year);
        return arrangedDate;
    }

    QString _arrangeDow(MyTime time) {
        QString arrangedDow = "";
        switch(time.dow) {
            case Monday:
                arrangedDow = "Lunedì";
                break;
            case Tuesday:
                arrangedDow = "Martedì";
                break;
            case Wednesday:
                arrangedDow = "Mercoledì";
                break;
            case Thursday:
                arrangedDow = "Giovedì";
                break;
            case Friday:
                arrangedDow = "Venerdì";
                break;
            case Saturday:
                arrangedDow = "Sabato";
                break;
            case Sunday:
                arrangedDow = "Domenica";
                break;
        }
        return arrangedDow;
    }

    QString _arrangeTime(MyTime time) {
        QString arrangedTime = "";
        QString separator = ":";
        if(time.hour < 10) arrangedTime += "0";
        arrangedTime += QString::number(time.hour);
        arrangedTime += separator;
        if(time.min <10) arrangedTime += "0";
        arrangedTime += QString::number(time.min);
        return arrangedTime;
    }

public:

    QtDisplay(ControlUnit* w, int length, int height) {
        this->w = w;
        this->length = length;
        this->height = height;
        w->setDimensions(length, height);
        displayChars = length * height;
    }

    void printSimpleText(char text[]) {
        QString rows[height];
        QString conv;

        conv = MyString::toQString(text);


        w->clearDisplay();

        if(conv.length() <= displayChars) {
            _arrangeWords(conv, rows);
            _printRows(rows);
        }
        else _displayError1();

    }

    void printData(char text1[], int data, char text2[]) {
        QString rows[height];

        QString conv1 = MyString::toQString(text1);
        QString conv2 = MyString::toQString(text2);

        QString conv = conv1 + " " + QString::number(data) + " " + conv2;

        w->clearDisplay();

        if(conv.length() <= displayChars) {
            _arrangeWords(conv, rows);
            _printRows(rows);
        }
        else _displayError1();
    }

    void printData(char text1[], int data1, char text2[], int data2, char text3[]) {
        QString rows[height];

        QString conv1 = MyString::toQString(text1);
        QString conv2 = MyString::toQString(text2);
        QString conv3 = MyString::toQString(text3);

        QString conv = conv1 + " " + QString::number(data1) + " " + conv2 + " " + QString::number(data2) + " " + conv3;

        w->clearDisplay();

        if(conv.length() <= displayChars) {
            _arrangeWords(conv, rows);
            _printRows(rows);
        }
        else _displayError1();
    }

    void printIn(char text[], int x, int y) {
        QString conv = MyString::toQString(text);

        w->setCursorDisplay(x, y);
        w->printOnDisplay(conv);
    }

    void printIn(int data, int x, int y) {
        QString conv = QString::number(data);

        w->setCursorDisplay(x, y);
        w->printOnDisplay(conv);
    }

    void printIn(QString text, int x, int y) {
        w->setCursorDisplay(x, y);
        w->printOnDisplay(text);
    }

    void showClock(MyTime timeIn) {
        w->clearDisplay();

        QString date;
        date = _arrangeDate(timeIn);
        printIn(date,0,1);
        QString dow;
        dow = _arrangeDow(timeIn);
        printIn(dow,0,0);
        QString time;
        time = _arrangeTime(timeIn);
        printIn(time,11,0);
        //printIn(QString::number(timeIn.sec),14,1);

    }

    void blinkAt(int x, int y) {
        w->hideCursorDisplay();
        w->setCursorDisplay(x, y);
        w->showCursorDisplay();
    }

    void noBlink() {
        w->hideCursorDisplay();
    }

    void clockSym() {
        w->setCursorDisplay(12, 1);
        w->printOnDisplay("c");
    }

    void noClockSym() {
        w->setCursorDisplay(12, 1);
        w->printOnDisplay(" ");
    }

    void dropSym() {
        w->setCursorDisplay(13, 1);
        w->printOnDisplay("d");
    }

    void noDropSym() {
        w->setCursorDisplay(13, 1);
        w->printOnDisplay(" ");
    }

    void checkSym() {
        w->setCursorDisplay(14, 1);
        w->printOnDisplay("c");
    }

    void noCheckSym() {
        w->setCursorDisplay(14, 1);
        w->printOnDisplay(" ");
    }

    void noSymbols() {
        noClockSym();
        noDropSym();
        noCheckSym();
    }

};

#endif
