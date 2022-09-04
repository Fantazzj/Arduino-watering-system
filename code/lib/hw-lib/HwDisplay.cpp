#include "../Config.h"

#ifndef HWDISPLAY_CPP
#define HWDISPLAY_CPP

#include <Wire.h>
#include "../../src/LiquidCrystal_I2C.h"
#include "../Display.cpp"


class HwDisplay: public Display {
private:
    LiquidCrystal_I2C* lcd;
    byte myAArray[8] = {0x08,0x04,0x0E,0x01,0x0F,0x11,0x0F,0x00};
    byte myA = 0;
    byte myEArray[8] = {0x08,0x04,0x0E,0x11,0x1E,0x10,0x0E,0x00};
    byte myE = 1;
    byte myIArray[8] = {0x08,0x04,0x00,0x0C,0x04,0x04,0x0E,0x00};
    byte myI = 2;
    byte myOArray[8] = {0x08,0x04,0x0E,0x11,0x11,0x11,0x0E,0x00};
    byte myO = 3;
    byte myUArray[8] = {0x08,0x04,0x11,0x11,0x11,0x13,0x0D,0x00};
    byte myU = 4;
    byte myDropArray[8] = {0x04,0x0A,0x0A,0x13,0x17,0x1F,0x0E,0x00};
    byte myDrop = 5;
    byte myCheckArray[8] = {0x00,0x00,0x00,0x01,0x02,0x14,0x08,0x00};
    byte myCheck = 6;
    byte myClockArray[8] = {0x00,0x00,0x0E,0x15,0x17,0x11,0x0E,0x00};
    byte myClock = 7;
    int8_t height = 0;
    int8_t lenght = 0;
    int8_t lcdLenght = 0;
    void displayError1() {
        lcd->print("Err. string");
        lcd->setCursor(0, 1);
        lcd->print("too big");
    }
    void arrangeWords(String text, String row[]) {
        String buffer = "";
        int8_t rowN = 0;

        if(text.charAt(text.length()-1) != ' ') text += " ";
        for(int8_t i=0;i<text.length();i++) {
            if(text.charAt(i) != ' ') buffer += text.charAt(i);
            else {
                if(row[rowN].length() + buffer.length() <= lenght) row[rowN] += (buffer + " ");
                else if(rowN+1 < height) row[++rowN] += (buffer + " ");
                buffer = "";
            }
        }
    }
    void printRows(String row[]) {
        for(int8_t rowN=0;rowN<height;rowN++) {
            lcd->setCursor(0, rowN);
            myPrint(row[rowN]);
        }
    }
    void myPrint(String text) {
        for(int8_t chr=0; chr<text.length(); chr++) {
            if(text.charAt(chr) == 'a' && text.charAt(chr+1) == '\'') {
                lcd->write(myA);
                chr++;
            }
            else if(text.charAt(chr) == 'e' && text.charAt(chr+1) == '\'') {
                lcd->write(myE);
                chr++;
            }
            else if(text.charAt(chr) == 'i' && text.charAt(chr+1) == '\'') {
                lcd->write(myI);
                chr++;
            }
            else if(text.charAt(chr) == 'o' && text.charAt(chr+1) == '\'') {
                lcd->write(myO);
                chr++;
            }
            else if(text.charAt(chr) == 'u' && text.charAt(chr+1) == '\'') {
                lcd->write(myU);
                chr++;
            }
            else lcd->print(text.charAt(chr));
        }
    }
    String arrangeDate(MyTime time) {
        String arrangedDate = "";
        String separator = "/";
        if(time.date < 10) arrangedDate += "0";
        arrangedDate += String(time.date);
        arrangedDate += separator;
        if(time.mon < 10) arrangedDate += "0";
        arrangedDate += String(time.mon);
        arrangedDate += separator;
        arrangedDate += String(time.year);
        return arrangedDate;
    }
    String arrangeDow(MyTime time) {
        String arrangedDow = "";
        switch(time.dow) {
            case Monday:
                arrangedDow = "Lunedi'";
                break;
            case Tuesday:
                arrangedDow = "Martedi'";
                break;
            case Wednesday:
                arrangedDow = "Mercoledi'";
                break;
            case Thursday:
                arrangedDow = "Giovedi'";
                break;
            case Friday:
                arrangedDow = "Venerdi'";
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
    String arrangeTime(MyTime time) {
        String arrangedTime = "";
        String separator = ":";
        if(time.hour < 10) arrangedTime += "0";
        arrangedTime += String(time.hour);
        arrangedTime += separator;
        if(time.min <10) arrangedTime += "0";
        arrangedTime += String(time.min);
        return arrangedTime;
    }

public:
    HwDisplay(int8_t address, int8_t lenght, int8_t height) {
        lcd = new LiquidCrystal_I2C(address, lenght, height);
        lcdLenght = height * lenght;
        this->height = height;
        this->lenght = lenght;
        lcd->init();
        lcd->backlight();
        lcd->createChar(myA, myAArray);
        lcd->createChar(myE, myEArray);
        lcd->createChar(myI, myIArray);
        lcd->createChar(myO, myOArray);
        lcd->createChar(myU, myUArray);
        lcd->createChar(myDrop, myDropArray);
        lcd->createChar(myCheck, myCheckArray);
        lcd->createChar(myClock, myClockArray);
        lcd->home();
    }
    void printSimpleText(char text[]) {
        String rows[height];
        String conv = MyString::toArduinoString(text);

        lcd->clear();

        if(conv.length() <= lcdLenght) {
            arrangeWords(conv, rows);
            printRows(rows);
        }
        else displayError1();
    }
    void printData(char text1[], int data, char text2[]) {
        String row[height];

        String conv1 = MyString::toArduinoString(text1);
        String conv2 = MyString::toArduinoString(text2);

        String conv = conv1 + " " + String(data) + " " + conv2;

        lcd->clear();
        if(conv.length() <= lcdLenght) {
            arrangeWords(conv, row);
            printRows(row);
        }
        else displayError1();
    }
    void printData(char text1[], int data1, char text2[], int data2, char text3[]) {
        String row[height];

        String conv1 = MyString::toArduinoString(text1);
        String conv2 = MyString::toArduinoString(text2);
        String conv3 = MyString::toArduinoString(text3);

        String conv = conv1 + " " + String(data1) + " " + conv2 + " " + String(data2) + " " + conv3;

        lcd->clear();
        if(conv.length() <= lcdLenght) {
            arrangeWords(conv, row);
            printRows(row);
        }
        else displayError1();
    }
    void printIn(char text[], int8_t col, int8_t row) {
        String conv = MyString::toArduinoString(text);
        
        lcd->setCursor(col, row);
        myPrint(conv);
    }
    void printIn(String text, int8_t col, int8_t row) {
        lcd->setCursor(col, row);
        myPrint(text);
    }
    void printIn(int8_t num, int8_t col, int8_t row) {
        String conv = String(num);

        lcd->setCursor(col, row);
        myPrint(conv);
    }
    void showClock(MyTime timeIn) {
        lcd->clear();
        String date;
        date = arrangeDate(timeIn);
        printIn(date,0,1);
        String dow;
        dow = arrangeDow(timeIn);
        printIn(dow,0,0);
        String time;
        time = arrangeTime(timeIn);
        printIn(time,11,0);
        //printIn(String(timeIn.sec),14,1);
    }
    void blinkAt(int8_t x, int8_t y) {
        lcd->setCursor(x, y);
        lcd->blink();
    }
    void noBlink() {
        lcd->noBlink();
    }
    void clockSym() {
        lcd->setCursor(12,1);
        lcd->write(myClock);
    }
    void noClockSym() {
        lcd->setCursor(12,1);
        lcd->print(" ");
    }
    void dropSym() {
        lcd->setCursor(13,1);
        lcd->write(myDrop);
    }
    void noDropSym() {
        lcd->setCursor(13,1);
        lcd->print(" ");
    }
    void checkSym() {
        lcd->setCursor(14,1);
        lcd->write(myCheck);
    }
    void noCheckSym() {
        lcd->setCursor(14,1);
        lcd->print(" ");
    }
    void noSymbols() {
        noClockSym();
        noDropSym();
        noCheckSym();
    }
    void backlight(){
        lcd->backlight();
    }
    void noBacklight(){
        lcd->noBacklight();
    }

protected:

};

#endif