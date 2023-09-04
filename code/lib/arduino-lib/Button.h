#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button {
public:
	Button(uint8_t pin, uint8_t mode, uint32_t snubberT);
	Button(uint8_t pin, uint8_t mode);
	uint8_t getPin();
	uint32_t getSnubberT();
	void setSnubberT(uint32_t snubberT);
	bool readRising();
	bool readFalling();
	bool readEdge();
	bool readLow();
	bool readHigh();

private:
	uint8_t _pin;
	uint8_t _oldState;
	uint32_t _prevoiusMillis;
	uint32_t _snubberT;
	void _init(uint8_t pin, uint8_t mode, uint32_t snubberT);
};

#endif
