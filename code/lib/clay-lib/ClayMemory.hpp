#ifndef CLAYMEMORY_HPP
#define CLAYMEMORY_HPP

#include "../core-lib/Memory.hpp"
#include "ClayControlUnit.hpp"
#include <fstream>

class ClayMemory : public Memory {
private:
	const std::string fileName = "./memory.bin";
	const std::ios::openmode inFlags = std::ios::in | std::ios::binary;
	const std::ios::openmode outFlags = std::ios::out | std::ios::binary | std::ios::trunc;
	int8_t maxFileSize;
	int8_t etvNum;

public:
	explicit ClayMemory(uint8_t etvNum);
	void begin();
	void saveEtvMinOn(uint8_t num, uint8_t minOn) override;
	uint8_t readEtvMinOn(uint8_t num) override;
	void saveEtvDays(uint8_t num, uint8_t days) override;
	uint8_t readEtvDays(uint8_t num) override;
	void saveStartTime(MyTime startTime) override;
	MyTime readStartTime() override;

protected:
};

#endif//CLAYMEMORY_HPP
