#include "ClayKeypad.hpp"

ClayKeypad::ClayKeypad() = default;

bool ClayKeypad::cancel() {
	const bool state = cancelState;
	cancelState = false;
	return state;
}

bool ClayKeypad::down() {
	const bool state = downState;
	downState = false;
	return state;
}

bool ClayKeypad::up() {
	const bool state = upState;
	upState = false;
	return state;
}

bool ClayKeypad::confirm() {
	const bool state = confirmState;
	confirmState = false;
	return state;
}

bool ClayKeypad::generalPressed() {
	return cancelState || upState || downState || confirmState;
}
