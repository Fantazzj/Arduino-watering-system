#ifndef CLAYMEMORY_HPP
#define CLAYMEMORY_HPP

#include "../core-lib/Memory.hpp"
#include "ClayControlUnit.hpp"
#include <fstream>

class ClayMemory final : public Memory {
private:
	std::string fileName;
	const std::ios::openmode IN_FLAGS = std::ios::in | std::ios::binary;
	const std::ios::openmode OUT_FLAGS = std::ios::out | std::ios::binary | std::ios::trunc;
	static constexpr int8_t MEMORY_SIZE = 2 * VALVE_NUM * sizeof(uint8_t) + 3 * sizeof(uint8_t);

public:
	explicit ClayMemory(const std::string& fileName);
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
