#ifndef HWMEMORY_HPP
#define HWMEMORY_HPP

#include "../core/Memory.hpp"

class HwMemory : public Memory {
private:

public:
	explicit HwMemory();
	void begin();
	void saveEtvMinOn(uint8_t num, uint8_t minOn) override;
	uint8_t readEtvMinOn(uint8_t num) override;
	void saveEtvDays(uint8_t num, uint8_t days) override;
	uint8_t readEtvDays(uint8_t num) override;
	void saveStartTime(MyTime startTime) override;
	MyTime readStartTime() override;

protected:
};

#endif//HWMEMORY_HPP
