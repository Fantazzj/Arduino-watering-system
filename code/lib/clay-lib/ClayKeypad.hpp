#ifndef CLAYKEYPAD_HPP
#define CLAYKEYPAD_HPP

#include "../core-lib/Keypad.hpp"

class ClayKeypad : public Keypad {
private:
	bool cancelState = false;
	bool downState = false;
	bool upState = false;
	bool confirmState = false;

public:
	explicit ClayKeypad();
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;
	friend class ClayControlUnit;

protected:
};


#endif//CLAYKEYPAD_HPP
