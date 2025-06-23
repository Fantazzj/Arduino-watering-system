#ifndef CLAYCLOCK_HPP
#define CLAYCLOCK_HPP

#include "../core/Clock.hpp"
#include "ClayControlUnit.hpp"

class ClayClock final : public Clock {
private:
	ClayControlUnit* w;

public:
	explicit ClayClock();
	void begin(ClayControlUnit* w);
	MyDateTime getDateTime() override;
	void setDateTime(MyDateTime time) override;

protected:
};


#endif//CLAYCLOCK_HPP
