#ifndef CLAYKEYPAD_HPP
#define CLAYKEYPAD_HPP

#include "../core/Keypad.hpp"

class ClayKeypad final : public Keypad {
public:
	explicit ClayKeypad();
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;
	void setCancel(bool state);
	void setDown(bool state);
	void setUp(bool state);
	void setConfirm(bool state);

private:
	bool cancelState;
	bool downState;
	bool upState;
	bool confirmState;
};


#endif//CLAYKEYPAD_HPP
