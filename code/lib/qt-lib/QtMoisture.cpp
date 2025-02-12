#include "QtMoisture.hpp"

QtMoisture::QtMoisture() {
	_w = nullptr;
}

void QtMoisture::begin(ControlUnit* w) {
	_w = w;
}

uint8_t QtMoisture::getMoisture() {
	return _w->getMoisture();
}
