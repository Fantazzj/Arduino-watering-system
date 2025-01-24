#include "UnitDisplay.hpp"

void UnitDisplay::backlight(bool state) {
	backlightState = state;
}
bool UnitDisplay::getBacklight() {
	return backlightState;
}
