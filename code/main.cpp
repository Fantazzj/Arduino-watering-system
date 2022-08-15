#include "lib/Config.h"

#ifdef QTDESKTOP

#include <QApplication>
#include <QThread>
#include <chrono>
#include <thread>
#include "code.ino"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    ControlUnit w;

    setup(&w);

    QThread *thread = QThread::create([]{
        while(true) {
            loop();
            std::this_thread::sleep_for(std::chrono::nanoseconds(100));
        }
    });
    thread->start();

    w.show();
    return a.exec();

}

#endif
