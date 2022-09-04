/*#ifndef QT_DEBUGGER_CPP
#define QT_DEBUGGER_CPP

#include "lib/Debugger.cpp"
#include "lib/ControlUnit.h"
#include "lib/MyString.cpp"

class QtDebugger: public Debugger {
private:
    ControlUnit* w;

public:
    QtDebugger(ControlUnit* w) {
        this->w = w;
    }

    void printText(char text[]) {
        QString qText = MyString::toQString(text);
        w->printOnConsole(qText);
    }

    void printData(int num) {
        QString qText = QString::number(num);
        w->printOnConsole(qText);
    }

protected:
};

#endif //QT_DEBUGGER_CPP
*/