#ifndef CLAYKEYPAD_HPP
#define CLAYKEYPAD_HPP

#include "../core-lib/Keypad.hpp"
#include "ClayControlUnit.hpp"

class ClayKeypad final : public Keypad {
private:
	ClayControlUnit* w;

public:
	explicit ClayKeypad();
	void begin(ClayControlUnit* w);
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;

protected:
};


#endif//CLAYKEYPAD_HPP
