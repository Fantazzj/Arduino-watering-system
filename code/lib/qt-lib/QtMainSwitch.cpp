#include "QtMainSwitch.hpp"

QtMainSwitch::QtMainSwitch() {
	w = nullptr;
}

void QtMainSwitch::begin(QtControlUnit* w) {
	this->w = w;
	w->disableValves();
}

void QtMainSwitch::turnOn() {
	w->enableValves();
}

void QtMainSwitch::turnOff() {
	w->disableValves();
}
