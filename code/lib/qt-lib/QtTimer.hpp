#ifndef QTTIMER_HPP
#define QTTIMER_HPP

#include "../core-lib/Timer.hpp"
#include <QThread>

class QtTimer : public Timer {
private:
public:
	explicit QtTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//QTTIMER_HPP
