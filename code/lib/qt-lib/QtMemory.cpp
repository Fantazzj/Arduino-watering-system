#include "QtMemory.hpp"

QtMemory::QtMemory(uint8_t etvNum) :
	Memory(etvNum), saveFile("memory.bin") {
	maxFileSize = 2 * _etvNum * sizeof(uint8_t) + 3 * sizeof(uint8_t);
}

void QtMemory::begin() {
	if(saveFile.size() >= maxFileSize)
		return;

	QByteArray memory;
	for(int8_t i = 0; i < maxFileSize; i++)
		memory.append((int8_t) 0);

	saveFile.open(QIODevice::WriteOnly);
	saveFile.write(memory);
	saveFile.close();
}

void QtMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	saveFile.open(QIODevice::ReadOnly);
	QByteArray memory = saveFile.readAll();
	saveFile.close();

	memory[num] = minOn;

	saveFile.open(QIODevice::WriteOnly);
	saveFile.write(memory);
	saveFile.close();
}

uint8_t QtMemory::readEtvMinOn(uint8_t num) {
	saveFile.open(QIODevice::ReadOnly);
	QByteArray memory = saveFile.readAll();
	saveFile.close();

	return memory[num];
}

void QtMemory::saveEtvDays(uint8_t num, uint8_t days) {
	saveFile.open(QIODevice::ReadOnly);
	QByteArray memory = saveFile.readAll();
	saveFile.close();

	memory[num + _etvNum] = days;

	saveFile.open(QIODevice::WriteOnly);
	saveFile.write(memory);
	saveFile.close();
}

uint8_t QtMemory::readEtvDays(uint8_t num) {
	saveFile.open(QIODevice::ReadOnly);
	QByteArray memory = saveFile.readAll();
	saveFile.close();

	return memory[num + _etvNum];
}

void QtMemory::saveStartTime(MyTime startTime) {
	saveFile.open(QIODevice::ReadOnly);
	QByteArray memory = saveFile.readAll();
	saveFile.close();

	memory[2 * _etvNum + 0] = startTime.hour;
	memory[2 * _etvNum + 1] = startTime.min;
	memory[2 * _etvNum + 2] = startTime.sec;

	saveFile.open(QIODevice::WriteOnly);
	saveFile.write(memory);
	saveFile.close();
}

MyTime QtMemory::readStartTime() {
	MyTime out;

	saveFile.open(QIODevice::ReadOnly);
	QByteArray memory = saveFile.readAll();
	saveFile.close();

	out.hour = memory[2 * _etvNum + 0];
	out.min = memory[2 * _etvNum + 1];
	out.sec = memory[2 * _etvNum + 2];
	return out;
}
