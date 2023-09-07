#ifndef MEMORY_HPP
#define MEMORY_HPP

#ifdef QTDESKTOP
#	include <cstdint>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

#include "MyTime.hpp"

class Memory {
private:
public:
	explicit Memory(uint8_t etvNum);
	virtual void saveEtvMinOn(uint8_t num, uint8_t minOn);
	virtual uint8_t readEtvMinOn(uint8_t num);
	virtual void saveEtvDays(uint8_t num, uint8_t days);
	virtual uint8_t readEtvDays(uint8_t num);
	virtual void saveStartTime(MyTime startTime);
	virtual MyTime readStartTime();

protected:
	uint8_t _etvNum;
};

#endif//MEMORY_HPP
