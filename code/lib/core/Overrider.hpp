#ifndef OVERRIDER_HPP
#define OVERRIDER_HPP

#if defined(QTDESKTOP)
#include <QThread>
#define wait(a) QThread::msleep(a)

#elif defined(HWARDUINO)
#define wait(a) delay(a)
#endif

#endif//OVERRIDER_HPP
