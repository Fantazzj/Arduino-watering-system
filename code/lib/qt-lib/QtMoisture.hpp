#ifndef QT_MOISTURE_CPP
#define QT_MOISTURE_CPP

#include "../core-lib/Moisture.hpp"
#include "ControlUnit.h"

class QtMoisture : public Moisture {
private:
	ControlUnit* _w;

public:
	explicit QtMoisture();
	void begin(ControlUnit* w);
	uint8_t getMoisture() override;

protected:
};

#endif
