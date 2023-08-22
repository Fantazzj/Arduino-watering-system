#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button {
public:
	Button(int pin, int mode, unsigned long snubberT);
	Button(int pin, int mode);
	int getPin();
	unsigned long getSnubberT();
	void setSnubberT(unsigned long snubberT);
	bool readRising();
	bool readFalling();
	bool readEdge();
	bool readLow();
	bool readHigh();

private:
	int _pin;
	int _oldState;
	unsigned long _prevoiusMillis;
	unsigned long _snubberT;
	void _init(int pin, int mode, unsigned long snubberT);
};

#endif
