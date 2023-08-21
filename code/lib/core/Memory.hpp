#ifndef MEMORY_HPP
#define MEMORY_HPP

#ifdef QTDESKTOP
#	include <cstdint>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

class Memory {
private:
public:
	Memory(int8_t etvNum);
	virtual void saveEtvMinOn(int8_t num, int8_t minOn);
	virtual int8_t readEtvMinOn(int8_t num);
	virtual void saveEtvDays(int8_t num, int8_t days);
	virtual int8_t readEtvDays(int8_t num);
protected:
	uint8_t _etvNum;
};

#endif//MEMORY_HPP
