#include "HwMainSwitch.hpp"

HwMainSwitch::HwMainSwitch(int8_t pin) {
	this->pin = pin;
}

void HwMainSwitch::begin() {
	pinMode(pin, OUTPUT);
	turnOff();
}

void HwMainSwitch::turnOff() {
	digitalWrite(pin, HIGH);
}

void HwMainSwitch::turnOn() {
	digitalWrite(pin, LOW);
}
