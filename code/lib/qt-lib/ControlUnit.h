#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#ifdef QTDESKTOP

#	include "../core/Keypad.hpp"
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
	void setKeypad(Keypad* keypad);
	void setDimensions(int length, int height);
	void printOnConsole(const QString& text);
	void printOnDisplay(QString text);
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
	Keypad* keypad;
	int8_t length = 16;
	int8_t height = 2;
	QCheckBox* etv[9];
	QLabel* matrix[16][2];
	QLabel* higlighted;
	int8_t x = 0;
	int8_t y = 0;
	QSlider moisture;
};

#endif

#endif// CONTROL_UNIT_H
