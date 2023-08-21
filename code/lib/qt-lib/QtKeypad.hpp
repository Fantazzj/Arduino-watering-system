#ifndef QT_KEYPAD_CPP
#define QT_KEYPAD_CPP

#include "../core/Keypad.hpp"

class QtKeypad : public Keypad {
private:
public:
	QtKeypad() = default;
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;

protected:
};

#endif//QT_KEYPAD_CPP
