#include "ClayMemory.hpp"

#include <filesystem>

using namespace std;
using namespace std::filesystem;

ClayMemory::ClayMemory(const string& fileName) {
	this->fileName = fileName;
}

void ClayMemory::begin() {
	if(exists(fileName) && file_size(fileName) == MEMORY_SIZE)
		return;

	char memoryBuffer[MEMORY_SIZE];
	for(auto& m: memoryBuffer)
		m = 0;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

void ClayMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	memoryBuffer[num] = minOn;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

uint8_t ClayMemory::readEtvMinOn(const uint8_t num) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	return memoryBuffer[num];
}

void ClayMemory::saveEtvDays(uint8_t num, uint8_t days) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	memoryBuffer[num + VALVE_NUM] = days;

	ofstream out(fileName, OUT_FLAGS);
	out.write(memoryBuffer, MEMORY_SIZE);
	out.close();
}

uint8_t ClayMemory::readEtvDays(const uint8_t num) {
	ifstream in(fileName, IN_FLAGS);

	char memoryBuffer[MEMORY_SIZE];

	in.read(memoryBuffer, MEMORY_SIZE);
	in.close();

	return memoryBuffer[num + VALVE_NUM];
}

void ClayMemory::saveStartTime(MyTime startTime) {
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

MyTime ClayMemory::readStartTime() {
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
