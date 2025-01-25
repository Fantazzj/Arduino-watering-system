#include "EditEtvTime.hpp"

EditEtvTime::EditEtvTime(PageController& controller) :
	Page(controller) {
	_etvEdit = 0;
	_timeEdit = _controller.etv[0].minOn;
}

PageNum EditEtvTime::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			if(_etvEdit > 0) {
				_etvEdit--;
				_timeEdit = _controller.etv[_etvEdit].minOn;
				return Stay;
			} else {
				_etvEdit = 0;
				_timeEdit = 0;
				return SettingsPage2;
			}

		case Down:
			if(_timeEdit <= 10) _timeEdit--;
			else _timeEdit -= 5;
			if(_timeEdit <= 0) _timeEdit = 0;
			return Stay;

		case Up:
			if(_timeEdit < 10) _timeEdit++;
			else _timeEdit += 5;
			return Stay;

		case Confirm:
			_controller.etv[_etvEdit].minOn = _timeEdit;
			_controller.memory.saveEtvMinOn(_etvEdit, _timeEdit);
			_etvEdit++;
			_timeEdit = _controller.etv[_etvEdit].minOn;
			if(_etvEdit >= _controller.etvNum)
				return HomePage;
			else return Stay;

		default:
			return Stay;
	}
}

void EditEtvTime::show() {
	if(_redraw) {
		_controller.display.printData((char*) "Etv", _etvEdit, (char*) "per", _timeEdit, (char*) "minuti");
		_controller.display.blinkAt(10, 0);
		_redraw = false;
	}
}
