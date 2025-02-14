#include "QtControlUnit.hpp"
#include "ui_QtControlUnit.h"

#include <QThread>

QtControlUnit::QtControlUnit(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::QtControlUnit) {
	ui->setupUi(this);

	keypad = nullptr;

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

	highlighted = matrix[0][0];

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

QtControlUnit::~QtControlUnit() {
	delete ui;
}

void QtControlUnit::setKeypad(QtKeypad* keypad) {
	this->keypad = keypad;
}

void QtControlUnit::printOnConsole(const char* text) {
	ui->textConsole->moveCursor(QTextCursor::End);
	QThread::msleep(1);
	ui->textConsole->insertPlainText(text);
}

void QtControlUnit::printOnConsole(char c) {
	ui->textConsole->moveCursor(QTextCursor::End);
	QThread::msleep(1);
	ui->textConsole->insertPlainText(QChar(c));
}

void QtControlUnit::printOnConsole(int n) {
	ui->textConsole->moveCursor(QTextCursor::End);
	QThread::msleep(1);
	ui->textConsole->insertPlainText(QString::number(n));
}

void QtControlUnit::printOnDisplay(QString text) {
	for(int i = x, j = 0; j < text.size() && i < length; i++, j++) {
		matrix[i][y]->setText(text.data()[j]);
	}
}

int8_t QtControlUnit::getLength() {
	return length;
}

int8_t QtControlUnit::getHeight() {
	return height;
}

void QtControlUnit::setCursorDisplay(int x, int y) {
	this->x = x;
	this->y = y;
}

void QtControlUnit::homeDisplay() {
	setCursorDisplay(0, 0);
}

void QtControlUnit::clearDisplay() {
	for(auto& labels: matrix) {
		for(auto& l: labels) {
			l->clear();
		}
	}
	homeDisplay();
}

void QtControlUnit::showCursorDisplay() {
	matrix[x][y]->setStyleSheet("QLabel { color : red; }");
	highlighted = matrix[x][y];
}

void QtControlUnit::hideCursorDisplay() {
	highlighted->setStyleSheet("QLabel { color : black; }");
}

void QtControlUnit::activateValve(int num) {
	etv[num]->setChecked(true);
}

void QtControlUnit::deactivateValve(int num) {
	etv[num]->setChecked(false);
}

void QtControlUnit::backlight() {
	ui->backlight->setValue(100);
}

void QtControlUnit::noBacklight() {
	ui->backlight->setValue(0);
}

int QtControlUnit::getMoisture() {
	return ui->moisture->value();
}

void QtControlUnit::on_confirmButton_clicked() {
	keypad->confirmState = true;
}

void QtControlUnit::on_upButton_clicked() {
	keypad->upState = true;
}

void QtControlUnit::on_downButton_clicked() {
	keypad->downState = true;
}

void QtControlUnit::on_cancelButton_clicked() {
	keypad->cancelState = true;
}

void QtControlUnit::enableValves() {
	for(auto& e: etv)
		e->setEnabled(true);
}

void QtControlUnit::disableValves() {
	for(auto& e: etv)
		e->setEnabled(false);
}
