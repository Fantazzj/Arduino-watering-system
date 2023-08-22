#include "QtMoisture.hpp"

QtMoisture::QtMoisture(ControlUnit* w) {
	_w = w;
}

uint8_t QtMoisture::getMoisture() {
	return _w->getMoisture();
}
