#ifndef HWMEMORY_HPP
#define HWMEMORY_HPP

#include "../core/Memory.hpp"
//#include <EEPROM.h>

class HwMemory : public Memory {
private:
public:
	HwMemory(int8_t etvNum);
	void saveEtvMinOn(int8_t num, int8_t minOn);
	int8_t readEtvMinOn(int8_t num);
	void saveEtvDays(int8_t num, int8_t days);
	int8_t readEtvDays(int8_t num);

protected:
};

#endif//HWMEMORY_HPP
