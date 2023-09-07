#include "QtMemory.hpp"

QtMemory::QtMemory(uint8_t etvNum) :
	Memory(etvNum) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(0);
	QDataStream stream(&saveFile);

	uint8_t buffer;
	uint8_t i, j;

	for(i = 0; i < 2 * (etvNum + 1) && !saveFile.atEnd(); i++)
		stream >> buffer;

	for(j = i; j < 2 * (etvNum + 1); j++)
		stream << uint8_t(0);

	for(i = 0; i < 3 && !saveFile.atEnd(); i++)
		stream >> buffer;

	for(j = i; j < 3; j++)
		stream << uint8_t(5);

	saveFile.close();
}

void QtMemory::saveEtvMinOn(uint8_t num, uint8_t minOn) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num);
	QDataStream stream(&saveFile);

	stream << minOn;
	saveFile.close();
}

uint8_t QtMemory::readEtvMinOn(uint8_t num) {
	uint8_t out;
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num);
	QDataStream stream(&saveFile);

	stream >> out;
	saveFile.close();
	return out;
}

void QtMemory::saveEtvDays(uint8_t num, uint8_t days) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num + _etvNum + 1);
	QDataStream stream(&saveFile);

	stream << days;
	saveFile.close();
}

uint8_t QtMemory::readEtvDays(uint8_t num) {
	uint8_t out;
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num + _etvNum + 1);
	QDataStream stream(&saveFile);

	stream >> out;
	saveFile.close();
	return out;
}

void QtMemory::saveStartTime(MyTime startTime) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(20);
	QDataStream stream(&saveFile);

	stream << startTime.hour << startTime.min << startTime.sec;
	saveFile.close();
}

MyTime QtMemory::readStartTime() {
	MyTime out;
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(20);
	QDataStream stream(&saveFile);

	stream >> out.hour >> out.min >> out.sec;
	saveFile.close();
	return out;
}
