#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayKeypad.hpp"

class ClayControlUnit {
private:
	ClayKeypad* keypad;

public:
	explicit ClayControlUnit();
	void show();
	void setKeypad(ClayKeypad* keypad);

protected:
};


#endif//CLAYCONTROLUNIT_HPP
