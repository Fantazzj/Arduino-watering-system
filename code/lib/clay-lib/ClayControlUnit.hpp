#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayKeypad.hpp"
#include "UI/clayUi.hpp"

class ClayControlUnit {
private:
	ClayUi ui;
	int8_t x = 0;
	int8_t y = 0;

public:
	explicit ClayControlUnit();
	void show();
	void setKeypad(ClayKeypad* keypad);
	void activateEtv(int8_t n);
	void deactivateEtv(int8_t n);
	void debuggerLog(std::string string);
	void printOnDisplay(std::string text);
	void setCursorDisplay(int8_t x, int8_t y);
	void clearDisplay();

protected:
};


#endif//CLAYCONTROLUNIT_HPP
