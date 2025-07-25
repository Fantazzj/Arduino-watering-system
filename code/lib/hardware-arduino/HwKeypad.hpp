#ifndef HWKEYPAD_CPP
#define HWKEYPAD_CPP

#include "../core/Keypad.hpp"
#include <Button.h>

class HwKeypad : public Keypad {
private:
	Button cancelButton;
	Button downButton;
	Button upButton;
	Button confirmButton;

public:
	explicit HwKeypad(uint8_t cancelPin, uint8_t downPin, uint8_t upPin, uint8_t confirmPin);
	void begin(int8_t mode);
	bool cancel() override;
	bool down() override;
	bool up() override;
	bool confirm() override;
	bool generalPressed() override;

protected:
};

#endif
