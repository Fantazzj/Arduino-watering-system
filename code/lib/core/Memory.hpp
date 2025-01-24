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
	virtual void saveEtvMinOn(uint8_t num, uint8_t minOn) = 0;
	virtual uint8_t readEtvMinOn(uint8_t num) = 0;
	virtual void saveEtvDays(uint8_t num, uint8_t days) = 0;
	virtual uint8_t readEtvDays(uint8_t num) = 0;
	virtual void saveStartTime(MyTime startTime) = 0;
	virtual MyTime readStartTime() = 0;

protected:
	uint8_t _etvNum;
};

#endif//MEMORY_HPP
