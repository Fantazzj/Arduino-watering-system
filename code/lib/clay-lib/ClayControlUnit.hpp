#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayKeypad.hpp"
#include "ClayUi/ClayControlUnitUi.hpp"

class ClayControlUnit {
private:
	ClayControlUnitUi ui;
	int8_t x = 0;
	int8_t y = 0;

public:
	explicit ClayControlUnit();
	void show();
	void setKeypad(ClayKeypad* keypad);
	void activateEtv(uint8_t n);
	void deactivateEtv(uint8_t n);
	void activateMainSwitch();
	void deactivateMainSwitch();
	void debuggerLog(const std::string& string);
	void printOnDisplay(const std::string& text);
	void setCursorDisplay(int8_t x, int8_t y);
	void clearDisplay();
	void hideCursorDisplay();
	void showCursorDisplay();
	[[nodiscard]] uint8_t getMoisture() const;
	void setDateTime(std::chrono::time_point<std::chrono::system_clock> dateTime);
	[[nodiscard]] std::chrono::time_point<std::chrono::system_clock> getDateTime() const;

protected:
};


#endif//CLAYCONTROLUNIT_HPP
