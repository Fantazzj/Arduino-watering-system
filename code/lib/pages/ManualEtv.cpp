#include "ManualEtv.hpp"

ManualEtv::ManualEtv(PageController& controller) :
	Page(controller) {
	_num = 1;
}

PageNum ManualEtv::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	if(_controller.autoCycle.etvOn == 0) {
		if(key == Up) {//TODO convert in switch
			_num++;
			if(_num > _controller.etvNum) _num = 1;
		}

		if(key == Down) {
			_num--;
			if(_num < 1) _num = _controller.etvNum;
		}

		if(key == Cancel) {
			_num = 1;
			return SettingsPage1;
		}

		if(key == Confirm) {
			_controller.mainSwitch.turnOn();
			wait(1000);
			_controller.etv[_num]->turnOn();
			_controller.autoCycle.etvOn = _num;
			return HomePage;
		}
	} else {
		if(key == Cancel) {
			return SettingsPage1;
		}

		if(key == Confirm) {
			_controller.etv[_controller.autoCycle.etvOn]->turnOff();
			wait(1000);
			_controller.mainSwitch.turnOff();
			_controller.autoCycle.etvOn = 0;
			_controller.autoCycle.watered = true;
			_controller.autoCycle.started = false;
			return HomePage;
		}
	}

	return Stay;
}

void ManualEtv::show() {
	if(_redraw) {
		if(_controller.autoCycle.etvOn == 0) _controller.display.printData((char*) "Accendi elettrovalvola", _num, (char*) "");
		else _controller.display.printData((char*) "Spegni elettrovalvola", _controller.autoCycle.etvOn, (char*) "");
		_controller.display.blinkAt(15, 1);
		_redraw = false;
	}
}
