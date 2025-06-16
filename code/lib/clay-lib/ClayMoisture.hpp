#ifndef CLAYMOISTURE_HPP
#define CLAYMOISTURE_HPP

#include "../core-lib/Moisture.hpp"
#include "ClayControlUnit.hpp"

class ClayMoisture final : public Moisture {
private:
	ClayControlUnit* w;

public:
	explicit ClayMoisture();
	void begin(ClayControlUnit* w);
	uint8_t getMoisture() override;

protected:
};

#endif//CLAYMOISTURE_HPP
