#include "HwKeypad.hpp"

HwKeypad::HwKeypad(uint8_t cancelPin, uint8_t downPin, uint8_t upPin, uint8_t confirmPin) :
	cancelButton(cancelPin, 250),
	downButton(downPin, 250),
	upButton(upPin, 250),
	confirmButton(confirmPin, 250) {
}

void HwKeypad::begin(int8_t mode) {
	cancelButton.begin(mode);
	downButton.begin(mode);
	upButton.begin(mode);
	confirmButton.begin(mode);
}

bool HwKeypad::cancel() {
	return cancelButton.readFalling();
}

bool HwKeypad::down() {
	return downButton.readFalling();
}

bool HwKeypad::up() {
	return upButton.readFalling();
}

bool HwKeypad::confirm() {
	return confirmButton.readFalling();
}

bool HwKeypad::generalPressed() {
	return cancelButton.readLow() || downButton.readLow() || upButton.readLow() || confirmButton.readLow();
}
