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
	HwKeypad(uint8_t cancelPin, uint8_t downPin, uint8_t upPin, uint8_t confirmPin);
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;

protected:
};

#endif
