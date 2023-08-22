#include "QtMemory.hpp"

QtMemory::QtMemory(int8_t etvNum) :
	Memory(etvNum) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(0);
	QDataStream stream(&saveFile);

	int8_t buffer;
	int8_t i, j, k;

	for(i = 0; i < 2 * (etvNum + 1) && !saveFile.atEnd(); i++)
		stream >> buffer;

	for(j = i; j < 2 * (etvNum + 1); j++)
		stream << int8_t(0);

	for(i = 0; i < 3 && !saveFile.atEnd(); i++)
		stream >> buffer;

	for(j = i; j < 3; j++)
		stream << int8_t(5);

	saveFile.close();
}

void QtMemory::saveEtvMinOn(int8_t num, int8_t minOn) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num);
	QDataStream stream(&saveFile);

	stream << minOn;
	saveFile.close();
}

int8_t QtMemory::readEtvMinOn(int8_t num) {
	int8_t out;
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num);
	QDataStream stream(&saveFile);

	stream >> out;
	saveFile.close();
	return out;
}

void QtMemory::saveEtvDays(int8_t num, int8_t days) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num + _etvNum + 1);
	QDataStream stream(&saveFile);

	stream << days;
	saveFile.close();
}

int8_t QtMemory::readEtvDays(int8_t num) {
	int8_t out;
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
