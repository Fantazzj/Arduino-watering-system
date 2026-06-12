#include "StdMemory.hpp"

#include <filesystem>

using namespace std;
using namespace std::filesystem;

StdMemory::StdMemory(const string& fileName) {
	this->fileName = fileName;

	if(exists(fileName) && file_size(fileName) == MEMORY_SIZE)
		return;

	char memoryBuffer[MEMORY_SIZE];
	for(auto& m: memoryBuffer)
		m = 0;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

void StdMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	memoryBuffer[num] = minOn;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

uint8_t StdMemory::readEtvMinOn(const uint8_t num) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	return memoryBuffer[num];
}

void StdMemory::saveEtvDays(uint8_t num, uint8_t days) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	memoryBuffer[num + VALVE_NUM] = days;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

uint8_t StdMemory::readEtvDays(const uint8_t num) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	return memoryBuffer[num + VALVE_NUM];
}

void StdMemory::saveStartTime(MyTime startTime) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	memoryBuffer[2 * VALVE_NUM + 0] = startTime.hour;
	memoryBuffer[2 * VALVE_NUM + 1] = startTime.min;
	memoryBuffer[2 * VALVE_NUM + 2] = startTime.sec;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

MyTime StdMemory::readStartTime() {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	MyTime out;
	out.hour = memoryBuffer[2 * VALVE_NUM + 0];
	out.min = memoryBuffer[2 * VALVE_NUM + 1];
	out.sec = memoryBuffer[2 * VALVE_NUM + 2];
	return out;
}
