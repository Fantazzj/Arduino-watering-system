#ifndef MOISTURE_HPP
#define MOISTURE_HPP

#if defined __has_include
#	if __has_include(<cstdlib>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
#endif

class Moisture {
private:
public:
	virtual ~Moisture() = default;
	virtual uint8_t getMoisture() = 0;

protected:
};

#endif//MOISTURE_HPP
