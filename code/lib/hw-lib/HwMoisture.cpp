#include "HwMoisture.hpp"

HwMoisture::HwMoisture(uint8_t pin) {
	_pin = pin;
}
uint8_t HwMoisture::getMoisture() {
	//uint8_t val = analogRead(_pin);
	//return map(val, 0, 1023, 0, 100);
	return 10;
}
