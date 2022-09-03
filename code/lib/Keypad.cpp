#ifndef KEYPAD_CPP
#define KEYPAD_CPP

class Keypad {
private:

public:
    Keypad() = default;

    bool cancelState = false;
    bool downState = false;
    bool upState = false;
    bool confirmState = false;

    virtual bool cancel() {return false;}
    virtual bool down() {return false;}
    virtual bool up() {return false;}
    virtual bool confirm() {return false;}
    virtual bool generalPressed() {return false;}

protected:
};

#endif //KEYPAD_CPP
