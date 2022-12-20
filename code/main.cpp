#include "lib/Config.h"

#ifdef QTDESKTOP

#	include "code.ino"
#	include <QApplication>
#	include <QThread>
#	include <thread>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	ControlUnit w;

	setup(&w);

	QThread* thread = QThread::create([] {
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
