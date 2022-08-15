#ifndef HWKEYPAD_CPP
#define HWKEYPAD_CPP

#include "../Keypad.cpp"
#include "../../src/Button.h"

class HwKeypad: public Keypad {
private:
    Button* cancelButton;
    Button* downButton;
    Button* upButton;
    Button* confirmButton;

public:
    HwKeypad(int cancelPin, int downPin, int upPin, int confirmPin) {
        cancelButton = new Button(cancelPin, INPUT_PULLUP, 500);
        downButton = new Button(downPin, INPUT_PULLUP, 500);
        upButton = new Button(upPin, INPUT_PULLUP, 500);
        confirmButton = new Button(confirmPin, INPUT_PULLUP, 500);
    }

    bool cancel() {
        return cancelButton->readFalling();
    }

    bool down() {
        return downButton->readFalling();
    }

    bool up() {
        return upButton->readFalling();
    }

    bool confirm() {
        return confirmButton->readFalling();
    }

protected:

};

#endif
