#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayKeypad.hpp"
#include "UI/clayUi.hpp"

class ClayControlUnit {
private:
	ClayKeypad* keypad;
	ClayUi ui;

public:
	explicit ClayControlUnit();
	void show();
	void setKeypad(ClayKeypad* keypad);

protected:
};


#endif//CLAYCONTROLUNIT_HPP
