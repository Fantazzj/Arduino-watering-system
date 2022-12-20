#include "Config.h"

#ifndef MY_STRING_CPP
#	define MY_STRING_CPP

#	ifdef QTDESKTOP
#		include <QString>
#	endif

class MyString {
private:
public:
#	ifdef QTDESKTOP
	static QString toQString(char text[]) {
		QString conv = "";
		for(int8_t i = 0; text[i] != '\0'; i++) conv += text[i];
		return conv;
	}
#	endif

#	ifdef HWARDUINO
	static String toArduinoString(char text[]) {
		String conv = "";
		for(int8_t i = 0; text[i] != '\0'; i++) conv += text[i];
		return conv;
	}
#	endif

protected:
};

#endif