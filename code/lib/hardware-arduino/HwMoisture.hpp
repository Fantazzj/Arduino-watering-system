#ifndef HW_MOISTURE_CPP
#define HW_MOISTURE_CPP

#include "../core/Moisture.hpp"

class HwMoisture : public Moisture {
private:
	uint8_t _pin;

public:
	explicit HwMoisture(uint8_t pin);
	uint8_t getMoisture() override;

protected:
};

#endif
