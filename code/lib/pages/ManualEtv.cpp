#include "ManualEtv.hpp"

ManualEtv::ManualEtv(PageController* controller) :
	Page(controller) {
	_num = 1;
}

PageNum ManualEtv::exec() {
	KeypadButton key = _controller->keypad();
	if(key != NoBtn) _redraw = true;

	if(_controller->getEtvOn() == 0) {
		if(key == Up) {//TODO convert in switch
			_num++;
			if(_num > _controller->getEtvNum()) _num = 1;
		}

		if(key == Down) {
			_num--;
			if(_num < 1) _num = _controller->getEtvNum();
		}

		if(key == Cancel) {
			_num = 1;
			return SettingsPage1;
		}

		if(key == Confirm) {
			_controller->setEtvState(_num, true);
			_controller->setEtvOn(_num);
			return HomePage;
		}
	} else {
		if(key == Cancel) {
			return SettingsPage1;
		}

		if(key == Confirm) {
			_controller->setEtvState(_controller->getEtvOn(), false);
			_controller->setEtvOn(0);
			_controller->autoCycleSetWatered(true);
			_controller->autoCycleSetStarted(false);
			return HomePage;
		}
	}

	return Stay;
}

void ManualEtv::show() {
	if(_redraw) {
		if(_controller->getEtvOn() == 0) _controller->displayPrint((char*) "Accendi elettrovalvola", _num, (char*) "");
		else _controller->displayPrint((char*) "Spegni elettrovalvola", _controller->getEtvOn(), (char*) "");
		_controller->displayShowCursor(15, 1);
		_redraw = false;
	}
}
