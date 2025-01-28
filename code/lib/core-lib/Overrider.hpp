#ifndef OVERRIDER_HPP
#define OVERRIDER_HPP

#if defined(QTDESKTOP)
#	include <QThread>
#	include <QDebug>
#	define wait(a) QThread::msleep(a)

#endif

#endif//OVERRIDER_HPP
