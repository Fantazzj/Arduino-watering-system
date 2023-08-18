#ifndef QT_MOISTURE_CPP
#define QT_MOISTURE_CPP

#include "../ControlUnit.h"
#include "../Moisture.hpp"

class QtMoisture : public Moisture {
private:
	ControlUnit* _w;

public:
	QtMoisture(ControlUnit* w);
	uint8_t getMoisture();

protected:
};

#endif
