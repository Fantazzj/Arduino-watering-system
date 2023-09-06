#include "HwMainSwitch.hpp"

HwMainSwitch::HwMainSwitch(int8_t pin) {
	this->pin = pin;
	pinMode(pin, OUTPUT);
    turnOff();
}

void HwMainSwitch::turnOff() {
	digitalWrite(pin, HIGH);
}

void HwMainSwitch::turnOn() {
	digitalWrite(pin, LOW);
}
