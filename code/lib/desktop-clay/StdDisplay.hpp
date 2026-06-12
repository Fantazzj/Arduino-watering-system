#ifndef CLAYDISPLAY_HPP
#define CLAYDISPLAY_HPP

#include "../core/UnitDisplay.hpp"
#include <string>

class StdDisplay final : public UnitDisplay {
	using string = std::string;

public:
	explicit StdDisplay();
	void printSimpleText(const char text[]) override;
	void printData(const char text1[], int8_t data, const char text2[]) override;
	void printData(const char text1[], int8_t data1, const char text2[], int8_t data2, const char text3[]) override;
	void printIn(const char text[], int8_t x, int8_t y) override;
	void printIn(int8_t data, int8_t x, int8_t y) override;
	void printIn(const string& data, int8_t x, int8_t y);
	void showClock(MyDateTime timeIn) override;
	void blinkAt(int8_t x, int8_t y) override;
	void noBlink() override;
	void clockSym(bool state) override;
	void dropSym(bool state) override;
	void checkSym(bool state) override;
	void setBacklight(bool state) override;
	[[nodiscard]] bool getBacklight() const override;
	int8_t* getBlinkChar();
	char* getTextLine(uint8_t n);


private:
	char text[DISPLAY_HEIGHT][DISPLAY_LENGTH];
	int8_t blinkChar[2];
	bool backlight;
	int8_t x;
	int8_t y;

	static void arrangeWords(string text, string rows[]);
	static string arrangeTime(MyTime time);
	static string arrangeDow(MyDate time);
	static string arrangeDate(MyDate time);
	void printRows(string rows[]);
	void printOnDisplay(string s);
	void clearDisplay();
	void setCursorDisplay(int8_t x, int8_t y);
	void displayError1();
	static constexpr int8_t displayChars = DISPLAY_HEIGHT * DISPLAY_LENGTH;
};

#endif//CLAYDISPLAY_HPP
