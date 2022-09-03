#ifndef QT_KEYPAD_CPP
#define QT_KEYPAD_CPP

#include "lib/Keypad.cpp"

class QtKeypad: public Keypad {
private:

public:
    QtKeypad() = default;

    bool cancel() {
        bool state;
        state = cancelState;
        cancelState = false;
        return state;
    }

    bool down() {
        bool state;
        state = downState;
        downState = false;
        return state;
    }

    bool up() {
        bool state;
        state = upState;
        upState = false;
        return state;
    }

    bool confirm() {
        bool state;
        state = confirmState;
        confirmState = false;
        return state;
    }

    bool generalPressed() {
        return cancelState or downState or upState or confirmState;
    }

protected:
};

#endif //QT_KEYPAD_CPP
