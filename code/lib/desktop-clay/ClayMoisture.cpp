#include "ClayMoisture.hpp"

ClayMoisture::ClayMoisture() :
	value{0} {}

uint8_t ClayMoisture::getMoisture() {
	return value;
}

void ClayMoisture::setMoisture(uint8_t value) {
	this->value = value;
}
