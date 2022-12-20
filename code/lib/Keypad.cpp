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

	virtual bool cancel() { return cancelState; }
	virtual bool down() { return downState; }
	virtual bool up() { return upState; }
	virtual bool confirm() { return confirmState; }
	virtual bool generalPressed() { return cancelState or downState or upState or confirmState; }

protected:
};

#endif//KEYPAD_CPP
