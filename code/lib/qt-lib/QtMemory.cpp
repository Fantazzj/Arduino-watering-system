#include "QtMemory.hpp"

QtMemory::QtMemory(int8_t etvNum) :
	Memory(etvNum) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(0);
	QDataStream stream(&saveFile);

	int8_t buffer;
	int8_t i, j;

	for(i = 0; i < 2 * (etvNum+1) && !saveFile.atEnd(); i++)
		stream >> buffer;

	for(j = i; j < 2 * (etvNum+1); j++)
		stream << int8_t(0);

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
	return out;
}

void QtMemory::saveEtvDays(int8_t num, int8_t days) {
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num+_etvNum+1);
	QDataStream stream(&saveFile);

	stream << days;
	saveFile.close();
}

int8_t QtMemory::readEtvDays(int8_t num) {
	int8_t out;
	QFile saveFile("memory.bin");
	saveFile.open(QIODevice::ReadWrite);
	saveFile.seek(num+_etvNum+1);
	QDataStream stream(&saveFile);

	stream >> out;
	return out;
}
