#ifndef KEYPAD_HPP
#define KEYPAD_HPP

class Keypad {
private:
public:
	virtual bool cancel() = 0;
	virtual bool down() = 0;
	virtual bool up() = 0;
	virtual bool confirm() = 0;
	virtual bool generalPressed() = 0;

protected:
};

#endif//KEYPAD_HPP
