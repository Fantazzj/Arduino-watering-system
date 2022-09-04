#ifndef HW_DEBUGGER_CPP
#define HW_DEBUGGER_CPP

#include "../Debugger.cpp"

class HwDebugger: public Debugger {
private:
public:
    HwDebugger(int baud) {
        Serial.begin(baud);
    }

    void printText(char text[]) {
        Serial.println(text);
    }

    void printData(int num) {
        Serial.println(num);
    }
    
protected:
};

#endif
