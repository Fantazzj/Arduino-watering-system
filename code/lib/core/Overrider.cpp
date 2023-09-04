#include "Overrider.hpp"

#if defined(QTDESKTOP)
void Timer::wait(uint64_t ms) {
	QThread::msleep(ms);
}
#elif defined(HWARDUINO)
void Timer::wait(uint64_t ms) {
	delay(ms);
}
#else


#endif
