#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

class Keypad {
private:
public:
	Keypad() = default;

	bool cancelState = false;
	bool downState = false;
	bool upState = false;
	bool confirmState = false;

	virtual bool cancel();
	virtual bool down();
	virtual bool up();
	virtual bool confirm();
	virtual bool generalPressed();

protected:
};

#endif//KEYPAD_HPP
