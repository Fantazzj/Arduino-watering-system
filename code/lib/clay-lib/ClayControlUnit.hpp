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
	void activateEtv(int8_t n);
	void deactivateEtv(int8_t n);
	void debuggerLog(std::string string);

protected:
};


#endif//CLAYCONTROLUNIT_HPP
