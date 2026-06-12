#pragma once

#include "../core/Moisture.hpp"

class StdMoisture final : public Moisture {
public:
	explicit StdMoisture();
	uint8_t getMoisture() override;
	void setMoisture(uint8_t value);

private:
	uint8_t value;
};
