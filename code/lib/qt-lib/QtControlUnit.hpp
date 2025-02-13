#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include "QtKeypad.hpp"
#include <QCheckBox>
#include <QLabel>
#include <QMainWindow>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
	class QtControlUnit;
}
QT_END_NAMESPACE

class QtControlUnit : public QMainWindow {
	Q_OBJECT

public:
	explicit QtControlUnit(QWidget* parent = nullptr);
	void setKeypad(QtKeypad* keypad);
	void printOnConsole(const QString& text);
	void printOnConsole(const char* text);
	void printOnConsole(char c);
	void printOnConsole(int n);
	void printOnDisplay(QString text);
	static int8_t getLength();
	static int8_t getHeight();
	void setCursorDisplay(int length, int height);
	void showCursorDisplay();
	void hideCursorDisplay();
	void homeDisplay();
	void clearDisplay();
	void activateValve(int num);
	void deactivateValve(int num);
	void enableValves();
	void disableValves();
	void backlight();
	void noBacklight();
	int getMoisture();
	~QtControlUnit() override;

private slots:
	void on_confirmButton_clicked();
	void on_upButton_clicked();
	void on_downButton_clicked();
	void on_cancelButton_clicked();

private:
	Ui::QtControlUnit* ui;
	QtKeypad* keypad;
	static const int8_t length = 16;
	static const int8_t height = 2;
	static const int8_t etvNum = 9;
	QCheckBox* etv[etvNum];
	QLabel* matrix[length][height];
	QLabel* highlighted;

	int8_t x = 0;
	int8_t y = 0;
};

#endif// CONTROL_UNIT_H
