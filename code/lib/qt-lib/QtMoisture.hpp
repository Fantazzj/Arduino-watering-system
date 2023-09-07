#ifndef QT_MOISTURE_CPP
#define QT_MOISTURE_CPP

#include "../core/Moisture.hpp"
#include "ControlUnit.h"

class QtMoisture : public Moisture {
private:
	ControlUnit* _w;

public:
	explicit QtMoisture(ControlUnit* w);
	uint8_t getMoisture() override;

protected:
};

#endif
