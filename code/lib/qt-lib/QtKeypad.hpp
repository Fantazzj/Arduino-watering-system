#ifndef QT_KEYPAD_CPP
#define QT_KEYPAD_CPP

#include "lib/Keypad.hpp"

class QtKeypad : public Keypad {
private:
public:
	QtKeypad() = default;
	bool cancel();
	bool down();
	bool up();
	bool confirm();
	//bool generalPressed();

protected:
};

#endif//QT_KEYPAD_CPP
