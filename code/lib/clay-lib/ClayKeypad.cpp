#include "ClayKeypad.hpp"

ClayKeypad::ClayKeypad() = default;

#include <iostream>

using namespace std;

bool ClayKeypad::cancel() {
	bool state;
	state = cancelState;
	cancelState = false;
	cout << "AAAAA" << endl;
	return state;
}

bool ClayKeypad::down() {
	bool state;
	state = downState;
	downState = false;
	return state;
}

bool ClayKeypad::up() {
	bool state;
	state = upState;
	upState = false;
	return state;
}

bool ClayKeypad::confirm() {
	bool state;
	state = confirmState;
	confirmState = false;
	return state;
}

bool ClayKeypad::generalPressed() {
	return cancelState || upState || downState || confirmState;
}
