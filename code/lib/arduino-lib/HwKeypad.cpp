#include "HwKeypad.hpp"

HwKeypad::HwKeypad(uint8_t cancelPin, uint8_t downPin, uint8_t upPin, uint8_t confirmPin) {
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
	return cancelButton->readLow() || downButton->readLow() || upButton->readLow() || confirmButton->readLow();
}
