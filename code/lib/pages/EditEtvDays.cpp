#include "EditEtvDays.hpp"

EditEtvDays::EditEtvDays(PageController& controller) :
	Page(controller) {
	_etvEdit = 0;
	_daysEdit = _controller.etv[0]->days;
}

PageNum EditEtvDays::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			if(_etvEdit > 0) {
				_etvEdit--;
				_daysEdit = _controller.etv[_etvEdit]->days;
				return Stay;
			} else {
				_etvEdit = 0;
				_daysEdit = 0;
				return SettingsPage6;
			}

		case Down:
			if(_daysEdit <= 10) _daysEdit--;
			else _daysEdit -= 5;
			if(_daysEdit <= 0) _daysEdit = 0;
			return Stay;

		case Up:
			if(_daysEdit < 10) _daysEdit++;
			else _daysEdit += 5;
			return Stay;

		case Confirm:
			_controller.etv[_etvEdit]->days = _daysEdit;
			_controller.memory.saveEtvDays(_etvEdit, _daysEdit);
			_etvEdit++;
			_daysEdit = _controller.etv[_etvEdit]->days;
			if(_etvEdit >= _controller.etvNum)
				return HomePage;
			else return Stay;

		default:
			return Stay;
	}
}

void EditEtvDays::show() {
	if(_redraw) {
		_controller.display.printData((char*) "Etv", _etvEdit, (char*) "ogni", _daysEdit, (char*) "giorni");
		_controller.display.blinkAt(11, 0);
		_redraw = false;
	}
}
