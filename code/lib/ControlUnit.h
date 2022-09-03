#include "Config.h"

#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#ifdef QTDESKTOP

#include <QMainWindow>
#include <QLabel>
#include <QCheckBox>
#include "Keypad.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class ControlUnit; }
QT_END_NAMESPACE

class ControlUnit : public QMainWindow {
    Q_OBJECT

public:
    ControlUnit(QWidget *parent = nullptr);
    void setKeypad(Keypad* keypad);
    void setDimensions(int length, int height);
    void printOnConsole(QString text);
    void printOnDisplay(QString text);
    void setCursorDisplay(int length, int height);
    void showCursorDisplay();
    void hideCursorDisplay();
    void homeDisplay();
    void clearDisplay();
    void activate(int num);
    void deactivate(int num);
    void backlight();
    void noBacklight();
    ~ControlUnit();

private slots:
    void on_confirmButton_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::ControlUnit* ui;
    Keypad* keypad;
    int length = 16;
    int height = 2;
    QCheckBox* etv[9];
    QLabel* matrix[16][2];
    QLabel* higlighted;
    int x = 0;
    int y = 0;

};

#endif 

#endif // CONTROL_UNIT_H
