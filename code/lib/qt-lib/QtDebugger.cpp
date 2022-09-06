/*#ifndef QT_DEBUGGER_CPP
#define QT_DEBUGGER_CPP

#include "lib/Debugger.cpp"
#include "lib/ControlUnit.h"
#include "lib/MyString.cpp"

class QtDebugger: public Debugger {
private:
    ControlUnit* _w;

public:
    QtDebugger(ControlUnit* _w) {
        this->_w = _w;
    }

    void printText(char text[]) {
        QString qText = MyString::toQString(text);
        _w->printOnConsole(qText);
    }

    void printData(int _num) {
        QString qText = QString::number(_num);
        _w->printOnConsole(qText);
    }

protected:
};

#endif //QT_DEBUGGER_CPP
*/