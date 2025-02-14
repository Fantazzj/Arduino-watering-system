#ifndef MOISTURE_HPP
#define MOISTURE_HPP

#ifdef QTDESKTOP
#	include <cstdint>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

class Moisture {
private:
public:
	virtual uint8_t getMoisture() = 0;

protected:
};

#endif//MOISTURE_HPP
