#include "UnitDisplay.hpp"

void UnitDisplay::backlight(bool state) {
	backlightState = state;
}
bool UnitDisplay::getBacklight() const {
	return backlightState;
}
