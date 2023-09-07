#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#if defined(QTDESKTOP)
#	include <QString>
#elif defined(HWARDUINO)
#	include <Arduino.h>
#endif

namespace MyString {

#if defined(QTDESKTOP)
	QString toQString(const char text[]);
#elif defined(HWARDUINO)
	String toArduinoString(const char text[]);
#endif

};// namespace MyString

#endif//MY_STRING_HPP
