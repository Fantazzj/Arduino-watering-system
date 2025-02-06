#include "ClayClock.hpp"

ClayClock::ClayClock() {
	//TODO: add definition
}

void ClayClock::begin(ClayControlUnit* w) {
	this->w = w;
}

MyDateTime ClayClock::getDateTime() {
	//TODO: add definition
	return MyDateTime();
}

void ClayClock::setDateTime(MyDateTime time) {
	w->debuggerLog("Set time to:\n");
	w->debuggerLog(std::to_string(time.time.hour) + ":" + std::to_string(time.time.min) + ":" + std::to_string(time.time.sec));
	w->debuggerLog(std::to_string(time.date.day) + "/" + std::to_string(time.date.mon) + "/" + std::to_string(time.date.year));
}
