#include "MyString.hpp"

#ifdef QTDESKTOP
QString MyString::toQString(char text[]) {
	QString conv = "";
	for(int8_t i = 0; text[i] != '\0'; i++) conv += text[i];
	return conv;
}
#endif

#ifdef ARDUINO
String MyString::toArduinoString(char text[]) {
	String conv = "";
	for(int8_t i = 0; text[i] != '\0'; i++) conv += text[i];
	return conv;
}
#endif
