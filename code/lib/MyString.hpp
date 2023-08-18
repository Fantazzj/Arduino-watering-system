#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#ifdef QTDESKTOP
#	include <QString>
#endif

class MyString {
private:
public:
#ifdef QTDESKTOP
	static QString toQString(char text[]);
#endif

#ifdef ARDUINO
	static String toArduinoString(char text[]);
#endif

protected:
};

#endif//MY_STRING_HPP
