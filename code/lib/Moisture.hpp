#ifndef MOISTURE_HPP
#define MOISTURE_HPP

#ifdef QTDESKTOP
#	include <cstdint>
#endif

class Moisture {
private:
public:
	Moisture() = default;
	virtual uint8_t getMoisture();

private:
};

#endif//MOISTURE_HPP
