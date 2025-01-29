#ifndef CLAYKEYPAD_HPP
#define CLAYKEYPAD_HPP

#include "../core-lib/Keypad.hpp"

class ClayKeypad : public Keypad {
private:
public:
	explicit ClayKeypad();
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;

protected:
};


#endif//CLAYKEYPAD_HPP
