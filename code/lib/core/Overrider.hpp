#ifndef OVERRIDER_HPP
#define OVERRIDER_HPP

#if defined(QTDESKTOP)
#	include <cstdint>
#	include <QThread>
#elif defined(HWARDUINO)
#	include <Arduino.h>
#endif

namespace Timer {
	void wait(uint64_t ms);
}// namespace Timer

#endif//OVERRIDER_HPP
