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
        cancelButton = new Button(cancelPin, INPUT_PULLUP, 250);
        downButton = new Button(downPin, INPUT_PULLUP, 250);
        upButton = new Button(upPin, INPUT_PULLUP, 250);
        confirmButton = new Button(confirmPin, INPUT_PULLUP, 250);
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

    bool generalPressed() {
        return cancelButton->readLow() or downButton->readLow() or upButton->readLow() or confirmButton->readLow();
    }

protected:

};

#endif
