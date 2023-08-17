#ifndef HWKEYPAD_CPP
#define HWKEYPAD_CPP

#include "../../src/Button.h"
#include "../Keypad.cpp"

class HwKeypad : public Keypad {
private:
	Button* cancelButton;
	Button* downButton;
	Button* upButton;
	Button* confirmButton;

public:
	HwKeypad(int8_t cancelPin, int8_t downPin, int8_t upPin, int8_t confirmPin);
	bool cancel();
	bool down();
	bool up();
	bool confirm();
	bool generalPressed();

protected:
};

#endif
