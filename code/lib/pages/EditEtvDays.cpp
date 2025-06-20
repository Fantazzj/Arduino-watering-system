#include "EditEtvDays.hpp"

EditEtvDays::EditEtvDays(PageController& controller) :
	Page(controller) {
	_etvEdit = 0;
	_daysEdit = _controller.etv.getDays(0);
}

PageNum EditEtvDays::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			if(_etvEdit > 0) {
				_etvEdit--;
				_daysEdit = _controller.etv.getDays(_etvEdit);
				return Stay;
			} else {
				_etvEdit = 0;
				_daysEdit = 0;
				return SettingsPage6;
			}

		case Down:
			if(_daysEdit <= 0) {
				_daysEdit = 0;
				return Stay;
			}
			if(_daysEdit <= 10) _daysEdit--;
			else _daysEdit -= 5;
			return Stay;

		case Up:
			if(_daysEdit >= 30) {
				_daysEdit = 30;
				return Stay;
			}
			if(_daysEdit < 10) _daysEdit++;
			else _daysEdit += 5;
			return Stay;

		case Confirm:
			_controller.etv.setDays(_etvEdit, _daysEdit);
			_controller.memory.saveEtvDays(_etvEdit, _daysEdit);
			_etvEdit++;
			_daysEdit = _controller.etv.getDays(_etvEdit);
			if(_etvEdit >= _controller.etvNum) {
#ifdef DEBUG
				_controller.debugger.print("New etv days: [ ");
				for(uint8_t e = 0; e < _controller.etvNum; e++) {
					_controller.debugger.print(_controller.etv.getDays(e));
					_controller.debugger.print(' ');
				}
				_controller.debugger.println(']');
#endif
				return HomePage;
			}
			else return Stay;

		default:
			return Stay;
	}
}

void EditEtvDays::show() {
	if(_redraw) {
		_controller.display.printData("Etv", _etvEdit + 1, "ogni", _daysEdit, "giorni");
		int8_t numDigits = 1 + (_daysEdit >= 10);
		_controller.display.blinkAt(10 + numDigits, 0);
		_redraw = false;
	}
}
