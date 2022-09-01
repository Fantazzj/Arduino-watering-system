#include "Config.h"

#ifdef QTDESKTOP

#include "ControlUnit.h"
#include "ui_ControlUnit.h"
#include "./ui_ControlUnit.h"

ControlUnit::ControlUnit(QWidget *parent): QMainWindow(parent), ui(new Ui::ControlUnit) {
    ui->setupUi(this);

    matrix[0][0] = ui->label_00;
    matrix[1][0] = ui->label_01;
    matrix[2][0] = ui->label_02;
    matrix[3][0] = ui->label_03;
    matrix[4][0] = ui->label_04;
    matrix[5][0] = ui->label_05;
    matrix[6][0] = ui->label_06;
    matrix[7][0] = ui->label_07;
    matrix[8][0] = ui->label_08;
    matrix[9][0] = ui->label_09;
    matrix[10][0] = ui->label_10;
    matrix[11][0] = ui->label_11;
    matrix[12][0] = ui->label_12;
    matrix[13][0] = ui->label_13;
    matrix[14][0] = ui->label_14;
    matrix[15][0] = ui->label_15;
    matrix[0][1] = ui->label_16;
    matrix[1][1] = ui->label_17;
    matrix[2][1] = ui->label_18;
    matrix[3][1] = ui->label_19;
    matrix[4][1] = ui->label_20;
    matrix[5][1] = ui->label_21;
    matrix[6][1] = ui->label_22;
    matrix[7][1] = ui->label_23;
    matrix[8][1] = ui->label_24;
    matrix[9][1] = ui->label_25;
    matrix[10][1] = ui->label_26;
    matrix[11][1] = ui->label_27;
    matrix[12][1] = ui->label_28;
    matrix[13][1] = ui->label_29;
    matrix[14][1] = ui->label_30;
    matrix[15][1] = ui->label_31;

    higlighted = matrix[0][0];

    etv[0] = ui->etv1;
    etv[1] = ui->etv2;
    etv[2] = ui->etv3;
    etv[3] = ui->etv4;
    etv[4] = ui->etv5;
    etv[5] = ui->etv6;
    etv[6] = ui->etv7;
    etv[7] = ui->etv8;
    etv[8] = ui->etv9;

}

ControlUnit::~ControlUnit() {
    delete ui;
    //exit(0);
}

void ControlUnit::setKeypad(Keypad *keypad) {
    this->keypad = keypad;
}

void ControlUnit::setDimensions(int length, int height) {
    this->length = length;
    this->height = height;
    clearDisplay();
}

void ControlUnit::printOnConsole(QString text) {
    ui->textConsole->append(text);
}

void ControlUnit::printOnDisplay(QString text) {
    for(int i=x, j=0; j<text.size() and i<length; i++, j++) {
        matrix[i][y]->setText(text.data()[j]);
    }
}

void ControlUnit::setCursorDisplay(int x, int y) {
    this->x = x;
    this->y = y;
}

void ControlUnit::homeDisplay() {
    setCursorDisplay(0, 0);
}

void ControlUnit::clearDisplay() {
    for(int i=0; i<length; i++) {
        for(int j=0; j<height; j++) {
            matrix[i][j]->clear();
        }
    }
    homeDisplay();
}

void ControlUnit::showCursorDisplay() {
    matrix[x][y]->setStyleSheet("QLabel { color : red; }");
    higlighted = matrix[x][y];
}

void ControlUnit::hideCursorDisplay() {
    higlighted->setStyleSheet("QLabel { color : black; }");
}

void ControlUnit::activate(int num) {
    etv[num-1]->setChecked(true);
}

void ControlUnit::deactivate(int num) {
    etv[num-1]->setChecked(false);
}

void ControlUnit::on_confirmButton_clicked() {
    keypad->confirmState = true;
}

void ControlUnit::on_upButton_clicked() {
    keypad->upState = true;
}

void ControlUnit::on_downButton_clicked() {
    keypad->downState = true;
}

void ControlUnit::on_cancelButton_clicked() {
    keypad->cancelState = true;
}

#endif
