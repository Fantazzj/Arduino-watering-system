#include "ClayMoisture.hpp"

ClayMoisture::ClayMoisture() {
	w = nullptr;
}

void ClayMoisture::begin(ClayControlUnit* w) {
	this->w = w;
}

uint8_t ClayMoisture::getMoisture() {
	return w->getMoisture();
}
