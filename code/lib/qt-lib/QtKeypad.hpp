#ifndef QT_KEYPAD_CPP
#define QT_KEYPAD_CPP

#include "../core-lib/Keypad.hpp"

class QtKeypad : public Keypad {
private:
	bool cancelState = false;
	bool downState = false;
	bool upState = false;
	bool confirmState = false;

public:
	explicit QtKeypad() = default;
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;
	friend class ControlUnit;

protected:
};

#endif//QT_KEYPAD_CPP
