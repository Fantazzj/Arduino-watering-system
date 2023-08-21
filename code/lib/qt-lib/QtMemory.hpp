#ifndef QTMEMORY_HPP
#define QTMEMORY_HPP

#include "../core/Memory.hpp"
#include <QFile>

class QtMemory : public Memory {
private:
public:
	QtMemory(int8_t etvNum);
	void saveEtvMinOn(int8_t num, int8_t minOn) override;
	int8_t readEtvMinOn(int8_t num) override;
	void saveEtvDays(int8_t num, int8_t days) override;
	int8_t readEtvDays(int8_t num) override;

protected:
};


#endif//QTMEMORY_HPP
