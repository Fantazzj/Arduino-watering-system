#include "StdMoisture.hpp"

StdMoisture::StdMoisture() :
	value{0} {}

uint8_t StdMoisture::getMoisture() {
	return value;
}

void StdMoisture::setMoisture(uint8_t value) {
	this->value = value;
}
