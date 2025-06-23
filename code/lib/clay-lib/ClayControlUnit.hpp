#ifndef CLAYCONTROLUNIT_HPP
#define CLAYCONTROLUNIT_HPP

#include "ClayUi/ClayControlUnitUi.hpp"

class ClayControlUnit {
private:
	ClayControlUnitUi ui;
	int8_t x = 0;
	int8_t y = 0;

public:
	explicit ClayControlUnit();
	void show();
	bool getCancelState();
	bool getDownState();
	bool getUpState();
	bool getConfirmState();
	bool getGeneralState() const;
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
	void setBacklight(bool state);
	[[nodiscard]] bool getBacklight() const;
	[[nodiscard]] uint8_t getMoisture() const;
	void setDateTime(std::chrono::local_time<std::chrono::seconds> dateTime);
	[[nodiscard]] std::chrono::local_time<std::chrono::seconds> getDateTime() const;

protected:
};


#endif//CLAYCONTROLUNIT_HPP
