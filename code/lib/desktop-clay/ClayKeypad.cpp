#include "ClayKeypad.hpp"

ClayKeypad::ClayKeypad() :
	cancelState{false}, downState{false}, upState{false}, confirmState{false} {}

bool ClayKeypad::cancel() {
	if(cancelState) {
		cancelState = false;
		return true;
	}
	return false;
}

bool ClayKeypad::down() {
	if(downState) {
		downState = false;
		return true;
	}
	return false;
}

bool ClayKeypad::up() {
	if(upState) {
		upState = false;
		return true;
	}
	return false;
}

bool ClayKeypad::confirm() {
	if(confirmState) {
		confirmState = false;
		return true;
	}
	return false;
}

bool ClayKeypad::generalPressed() {
	return cancelState || downState || upState || confirmState;
}

void ClayKeypad::setCancel(const bool state) {
	cancelState = state;
}

void ClayKeypad::setDown(const bool state) {
	downState = state;
}

void ClayKeypad::setUp(const bool state) {
	upState = state;
}

void ClayKeypad::setConfirm(const bool state) {
	confirmState = state;
}
