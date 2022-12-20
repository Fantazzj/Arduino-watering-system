#ifndef HW_MOISTURE_CPP
#define HW_MOISTURE_CPP

#include "../Moisture.cpp"

class HwMoisture : public Moisture {
private:
	uint8_t _pin;

public:
	HwMoisture(uint8_t pin) {
		_pin = pin;
	}
	uint8_t getMoisture() {
		uint8_t val = analogRead(_pin);
		//return map(val, 0, 1023, 0, 100);
		return 10;
	}

protected:
};

#endif
