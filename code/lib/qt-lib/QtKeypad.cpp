#include "QtKeypad.hpp"

bool QtKeypad::cancel() {
	bool state;
	state = cancelState;
	cancelState = false;
	return state;
}

bool QtKeypad::down() {
	bool state;
	state = downState;
	downState = false;
	return state;
}

bool QtKeypad::up() {
	bool state;
	state = upState;
	upState = false;
	return state;
}

bool QtKeypad::confirm() {
	bool state;
	state = confirmState;
	confirmState = false;
	return state;
}

bool QtKeypad::generalPressed() {
	return cancelState || upState || downState || confirmState;
}
