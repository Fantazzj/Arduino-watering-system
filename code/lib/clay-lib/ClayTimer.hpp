#ifndef CLAYTIMER_HPP
#define CLAYTIMER_HPP

#include "../core-lib/Timer.hpp"
#include "ClayControlUnit.hpp"

class ClayTimer : public Timer {
private:
public:
	explicit ClayTimer();
	void wait(unsigned long t) override;
	unsigned long millis() override;

protected:
};

#endif//CLAYTIMER_HPP
