#ifndef QTMEMORY_HPP
#define QTMEMORY_HPP

#include "../core/Memory.hpp"
#include <QFile>

class QtMemory : public Memory {
private:
public:
	QtMemory(int8_t etvNum);
	void saveEtvMinOn(int8_t num, int8_t minOn);
	int8_t readEtvMinOn(int8_t num);
	void saveEtvDays(int8_t num, int8_t days);
	int8_t readEtvDays(int8_t num);

protected:
};


#endif//QTMEMORY_HPP
