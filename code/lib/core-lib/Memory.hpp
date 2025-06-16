#ifndef MEMORY_HPP
#define MEMORY_HPP

#if defined __has_include
#	if __has_include(<cstdlib>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
#endif

#include "../date-time-lib/MyTime.hpp"

class Memory {
private:
public:
	virtual ~Memory() = default;
	virtual void saveEtvMinOn(uint8_t num, uint8_t minOn) = 0;
	virtual uint8_t readEtvMinOn(uint8_t num) = 0;
	virtual void saveEtvDays(uint8_t num, uint8_t days) = 0;
	virtual uint8_t readEtvDays(uint8_t num) = 0;
	virtual void saveStartTime(MyTime startTime) = 0;
	virtual MyTime readStartTime() = 0;
};

#endif//MEMORY_HPP
