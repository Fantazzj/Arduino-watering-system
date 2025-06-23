#include "ManualEtv.hpp"

ManualEtv::ManualEtv(PageController& controller) :
	Page(controller) {
	_num = 0;
}

PageNum ManualEtv::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	if(_controller.autoCycle.etvOn == -1) {
		switch(key) {
			case Cancel:
				_num = 0;
				return SettingsPage1;
			case Up:
				_num++;
				if(_num >= VALVE_NUM) _num = 0;
				return Stay;
			case Down:
				_num--;
				if(_num < 0) _num = VALVE_NUM - 1;
				return Stay;
			case Confirm:
				_controller.etv.turnOn(_num);
				_controller.timer.wait(1000);

				_controller.mainSwitch.turnOn();
#ifdef DEBUG
				_controller.debugger.print("Manually turn on Etv");
				_controller.debugger.println(_num + 1);
#endif
				_controller.autoCycle.etvOn = _num;

				return HomePage;
			default:
				return Stay;
		}
	}

	switch(key) {
		case Cancel:
			return SettingsPage1;

		case Confirm:
			_controller.mainSwitch.turnOff();
			_controller.timer.wait(1000);

			_controller.etv.turnOff(_controller.autoCycle.etvOn);
#ifdef DEBUG
			_controller.debugger.print("Manually turn off Etv");
			_controller.debugger.println(_controller.autoCycle.etvOn + 1);
#endif
			_controller.autoCycle.etvOn = -1;

			_controller.autoCycle.watered = true;
			_controller.autoCycle.started = false;
			return HomePage;

		default:
			return Stay;
	}
}

void ManualEtv::show() {
	if(_redraw) {
		if(_controller.autoCycle.etvOn == -1) _controller.display.printData("Accendi elettrovalvola", _num + 1, "");
		else _controller.display.printData("Spegni elettrovalvola", _controller.autoCycle.etvOn + 1, "");
		_controller.display.blinkAt(15, 1);
		_redraw = false;
	}
}
