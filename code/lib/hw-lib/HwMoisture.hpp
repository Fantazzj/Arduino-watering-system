#ifndef HW_MOISTURE_CPP
#define HW_MOISTURE_CPP

#include "../Moisture.cpp"

class HwMoisture : public Moisture {
private:
	uint8_t _pin;

public:
	HwMoisture(uint8_t pin);
	uint8_t getMoisture();

protected:
};

#endif
