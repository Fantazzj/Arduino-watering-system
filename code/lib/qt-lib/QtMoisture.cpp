#ifndef QT_MOISTURE_CPP
#define QT_MOISTURE_CPP

#include "../Moisture.cpp"
#include "../ControlUnit.h"

class QtMoisture: public Moisture {
private:
    ControlUnit* _w;

public:
    QtMoisture(ControlUnit* w) {
        _w = w;
    }
    uint8_t getMoisture() {
        return _w->getMoisture();
    }

protected:
};

#endif