#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#ifdef QTDESKTOP
#	include <QString>
#endif

#ifdef HWARDUINO
#	include <Arduino.h>
#endif

namespace MyString {

#ifdef QTDESKTOP
	QString toQString(const char text[]);
#endif

#ifdef ARDUINO
	String toArduinoString(const char text[]);
#endif

};// namespace MyString

#endif//MY_STRING_HPP
