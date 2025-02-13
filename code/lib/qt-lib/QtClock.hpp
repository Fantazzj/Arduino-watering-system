#ifndef QT_CLOCK_CPP
#define QT_CLOCK_CPP

#include "../core-lib/Clock.hpp"
#include "QtControlUnit.hpp"
#include <QString>

class QtClock : public Clock {
private:
	QtControlUnit* _w;

public:
	explicit QtClock();
	void begin(QtControlUnit* w);
	MyDateTime getDateTime() override;
	void setDateTime(MyDateTime time) override;

protected:
};

#endif
