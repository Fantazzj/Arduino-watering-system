#ifndef MOISTURE_CPP
#define MOISTURE_CPP

class Moisture {
private:
public:
	Moisture() = default;
	virtual uint8_t getMoisture() {
		return 50;
	}

private:
};

#endif
