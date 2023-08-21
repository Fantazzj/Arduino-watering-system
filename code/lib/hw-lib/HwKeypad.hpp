#ifndef HWKEYPAD_CPP
#define HWKEYPAD_CPP

#include "Button.h"
#include "../core/Keypad.hpp"

class HwKeypad : public Keypad {
private:
	Button* cancelButton;
	Button* downButton;
	Button* upButton;
	Button* confirmButton;

public:
	HwKeypad(int8_t cancelPin, int8_t downPin, int8_t upPin, int8_t confirmPin);
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;

protected:
};

#endif
