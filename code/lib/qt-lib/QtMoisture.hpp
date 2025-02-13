#ifndef QT_MOISTURE_CPP
#define QT_MOISTURE_CPP

#include "../core-lib/Moisture.hpp"
#include "QtControlUnit.hpp"

class QtMoisture : public Moisture {
private:
	QtControlUnit* _w;

public:
	explicit QtMoisture();
	void begin(QtControlUnit* w);
	uint8_t getMoisture() override;

protected:
};

#endif
