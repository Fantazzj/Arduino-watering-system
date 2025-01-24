#include "QtMainSwitch.hpp"

QtMainSwitch::QtMainSwitch(ControlUnit* w) {
	this->w = w;
	w->disableValves();
}

void QtMainSwitch::turnOn() {
	w->enableValves();
}

void QtMainSwitch::turnOff() {
	w->disableValves();
}
