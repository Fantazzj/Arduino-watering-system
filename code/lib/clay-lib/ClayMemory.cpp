#include "ClayMemory.hpp"

#include <filesystem>

using std::ifstream;
using std::ios;
using std::ofstream;
using std::streamsize;
using std::filesystem::file_size;
using std::filesystem::exists;

ClayMemory::ClayMemory(uint8_t etvNum) {
	maxFileSize = 2 * etvNum * sizeof(uint8_t) + 3 * sizeof(uint8_t);
	this->etvNum = etvNum;
}

void ClayMemory::begin() {
	if(exists(fileName) && file_size(fileName) >= maxFileSize)
		return;

	char memory[maxFileSize];
	for(int8_t i = 0; i < maxFileSize; i++)
		memory[i] = 0;

	ofstream out(fileName, outFlags);
	out.write(memory, maxFileSize);
	out.close();
}

void ClayMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	ifstream in(fileName, inFlags);

	in.seekg(0, ios::end);
	streamsize length = in.tellg();
	in.seekg(0, ios::beg);

	char memory[length];

	in.read(memory, length);
	in.close();

	memory[num] = minOn;

	ofstream out(fileName, outFlags);
	out.write(memory, length);
	out.close();
}

uint8_t ClayMemory::readEtvMinOn(uint8_t num) {
	ifstream in(fileName, inFlags);

	in.seekg(0, ios::end);
	streamsize length = in.tellg();
	in.seekg(0, ios::beg);

	char memory[length];

	in.read(memory, length);
	in.close();

	return memory[num];
}

void ClayMemory::saveEtvDays(uint8_t num, uint8_t days) {
	ifstream in(fileName, inFlags);

	in.seekg(0, ios::end);
	streamsize length = in.tellg();
	in.seekg(0, ios::beg);

	char memory[length];

	in.read(memory, length);
	in.close();

	memory[num + etvNum] = days;

	ofstream out(fileName, outFlags);
	out.write(memory, length);
	out.close();
}

uint8_t ClayMemory::readEtvDays(uint8_t num) {
	ifstream in(fileName, inFlags);

	in.seekg(0, ios::end);
	streamsize length = in.tellg();
	in.seekg(0, ios::beg);

	char memory[length];

	in.read(memory, length);
	in.close();

	return memory[num + etvNum];
}

void ClayMemory::saveStartTime(MyTime startTime) {
	ifstream in(fileName, inFlags);

	in.seekg(0, ios::end);
	streamsize length = in.tellg();
	in.seekg(0, ios::beg);

	char memory[length];

	in.read(memory, length);
	in.close();

	memory[2 * etvNum + 0] = startTime.hour;
	memory[2 * etvNum + 1] = startTime.min;
	memory[2 * etvNum + 2] = startTime.sec;

	ofstream out(fileName, outFlags);
	out.write(memory, length);
	out.close();
}

MyTime ClayMemory::readStartTime() {
	ifstream in(fileName, inFlags);

	in.seekg(0, ios::end);
	streamsize length = in.tellg();
	in.seekg(0, ios::beg);

	char memory[length];

	in.read(memory, length);
	in.close();

	MyTime out;
	out.hour = memory[2 * etvNum + 0];
	out.min = memory[2 * etvNum + 1];
	out.sec = memory[2 * etvNum + 2];
	return out;
}
