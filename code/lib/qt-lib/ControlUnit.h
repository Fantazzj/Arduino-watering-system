#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#ifdef QTDESKTOP

#	include "QtKeypad.hpp"
#	include <QCheckBox>
#	include <QLabel>
#	include <QMainWindow>
#	include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
	class ControlUnit;
}
QT_END_NAMESPACE

class ControlUnit : public QMainWindow {
	Q_OBJECT

public:
	ControlUnit(QWidget* parent = nullptr);
	void setKeypad(QtKeypad* keypad);
	void printOnConsole(const QString& text);
	void printOnDisplay(QString text);
	int8_t getLength();
	int8_t getHeight();
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
	~ControlUnit();

private slots:
	void on_confirmButton_clicked();
	void on_upButton_clicked();
	void on_downButton_clicked();
	void on_cancelButton_clicked();

private:
	Ui::ControlUnit* ui;
	QtKeypad* keypad;
	static const int8_t length = 16;
	static const int8_t height = 2;
	static const int8_t etvNum = 9;
	//QCheckBox* etv[etvNum];
	//QLabel* matrix[length][height];
	QCheckBox* etv[etvNum];
	QLabel* matrix[length][height];
	QLabel* higlighted;

	int8_t x = 0;
	int8_t y = 0;
};

#endif

#endif// CONTROL_UNIT_H
