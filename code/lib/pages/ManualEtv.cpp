#include "ManualEtv.hpp"

ManualEtv::ManualEtv(PageController& controller) :
	Page(controller) {
	_num = 0;
}

PageNum ManualEtv::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	if(_controller.autoCycle.etvOn == -1) {
		if(key == Up) {//TODO convert in switch
			_num++;
			if(_num >= _controller.etvNum) _num = 0;
		}

		if(key == Down) {
			_num--;
			if(_num < 0) _num = _controller.etvNum - 1;
		}

		if(key == Cancel) {
			_num = 0;
			return SettingsPage1;
		}

		if(key == Confirm) {
			_controller.mainSwitch.turnOn();
			_controller.timer.wait(1000);
			_controller.etv.turnOn(_num);
			_controller.autoCycle.etvOn = _num;
			return HomePage;
		}
	} else {
		if(key == Cancel) {
			return SettingsPage1;
		}

		if(key == Confirm) {
			_controller.etv.turnOff(_controller.autoCycle.etvOn);
			_controller.timer.wait(1000);
			_controller.mainSwitch.turnOff();
			_controller.autoCycle.etvOn = -1;
			_controller.autoCycle.watered = true;
			_controller.autoCycle.started = false;
			return HomePage;
		}
	}

	return Stay;
}

void ManualEtv::show() {
	if(_redraw) {
		if(_controller.autoCycle.etvOn == -1) _controller.display.printData("Accendi elettrovalvola", _num + 1, "");
		else _controller.display.printData("Spegni elettrovalvola", _controller.autoCycle.etvOn + 1, "");
		_controller.display.blinkAt(15, 1);
		_redraw = false;
	}
}
