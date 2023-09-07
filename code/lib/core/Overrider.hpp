#ifndef OVERRIDER_HPP
#define OVERRIDER_HPP

#if defined(QTDESKTOP)
#	include <QThread>
#	define wait(a) QThread::msleep(a)

#elif defined(HWARDUINO)
#	define wait(a) delay(a)

#endif

#if !defined(wait)
#	error Missing override functions
#endif

#endif//OVERRIDER_HPP
