#include "HwKeypad.hpp"

HwKeypad::HwKeypad(int8_t cancelPin, int8_t downPin, int8_t upPin, int8_t confirmPin) {
	cancelButton = new Button(cancelPin, INPUT_PULLUP, 250);
	downButton = new Button(downPin, INPUT_PULLUP, 250);
	upButton = new Button(upPin, INPUT_PULLUP, 250);
	confirmButton = new Button(confirmPin, INPUT_PULLUP, 250);
}

bool HwKeypad::cancel() {
	return cancelButton->readFalling();
}

bool HwKeypad::down() {
	return downButton->readFalling();
}

bool HwKeypad::up() {
	return upButton->readFalling();
}

bool HwKeypad::confirm() {
	return confirmButton->readFalling();
}

bool HwKeypad::generalPressed() {
	return cancelButton->readLow() or downButton->readLow() or upButton->readLow() or confirmButton->readLow();
}
