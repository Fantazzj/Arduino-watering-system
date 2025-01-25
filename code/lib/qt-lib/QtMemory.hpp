#ifndef QTMEMORY_HPP
#define QTMEMORY_HPP

#include "../core/Memory.hpp"
#include <QFile>

class QtMemory : public Memory {
private:
	int8_t maxFileSize;
	QFile saveFile;

public:
	explicit QtMemory(uint8_t etvNum);
	void begin();
	void saveEtvMinOn(uint8_t num, uint8_t minOn) override;
	uint8_t readEtvMinOn(uint8_t num) override;
	void saveEtvDays(uint8_t num, uint8_t days) override;
	uint8_t readEtvDays(uint8_t num) override;
	void saveStartTime(MyTime startTime) override;
	MyTime readStartTime() override;

protected:
};


#endif//QTMEMORY_HPP
