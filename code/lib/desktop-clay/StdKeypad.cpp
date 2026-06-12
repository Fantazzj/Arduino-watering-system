#include "StdKeypad.hpp"

StdKeypad::StdKeypad() :
	cancelState{false}, downState{false}, upState{false}, confirmState{false} {}

bool StdKeypad::cancel() {
	if(cancelState) {
		cancelState = false;
		return true;
	}
	return false;
}

bool StdKeypad::down() {
	if(downState) {
		downState = false;
		return true;
	}
	return false;
}

bool StdKeypad::up() {
	if(upState) {
		upState = false;
		return true;
	}
	return false;
}

bool StdKeypad::confirm() {
	if(confirmState) {
		confirmState = false;
		return true;
	}
	return false;
}

bool StdKeypad::generalPressed() {
	return cancelState || downState || upState || confirmState;
}

void StdKeypad::setCancel(const bool state) {
	cancelState = state;
}

void StdKeypad::setDown(const bool state) {
	downState = state;
}

void StdKeypad::setUp(const bool state) {
	upState = state;
}

void StdKeypad::setConfirm(const bool state) {
	confirmState = state;
}
