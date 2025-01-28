#include "QtDebugger.hpp"

QtDebugger::QtDebugger() = default;

void QtDebugger::print(const char* text) {
	qDebug() << text;
}

void QtDebugger::print(char c) {
	qDebug() << c;
}

void QtDebugger::print(int n) {
	qDebug() << n;
}
