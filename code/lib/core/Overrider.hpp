#ifndef OVERRIDER_HPP
#define OVERRIDER_HPP

#if defined(QTDESKTOP)
#	include <QThread>
#	include <QDebug>
#	define wait(a) QThread::msleep(a)
#	define debug(a) qDebug() << (a)

#elif defined(HWARDUINO)
#	define wait(a) delay(a)
#	define debug(a) mySerial.print(a)

#endif

#if !defined(wait) || !defined(debug)
#	error Missing override functions
#endif

#endif//OVERRIDER_HPP
