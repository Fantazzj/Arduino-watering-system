#ifndef GENERALSWITCH_HPP
#define GENERALSWITCH_HPP

class MainSwitch {
private:
public:
	virtual ~MainSwitch() = default;
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
};

#endif//GENERALSWITCH_HPP
