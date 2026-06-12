#ifndef CLAYMOISTURE_HPP
#define CLAYMOISTURE_HPP

#include "../core/Moisture.hpp"

class StdMoisture final : public Moisture {
public:
	explicit StdMoisture();
	uint8_t getMoisture() override;
	void setMoisture(uint8_t value);

private:
	uint8_t value;
};

#endif//CLAYMOISTURE_HPP
