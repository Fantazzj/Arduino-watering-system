#include "EditEtvTime.hpp"

EditEtvTime::EditEtvTime(PageController& controller) :
	Page(controller) {
	_etvEdit = 0;
	_timeEdit = _controller.etv.getMinOn(0);
}

PageNum EditEtvTime::exec() {
	KeypadButton key = _controller.keypadButton();
	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			if(_etvEdit > 0) {
				_etvEdit--;
				_timeEdit = _controller.etv.getMinOn(_etvEdit);
				return Stay;
			} else {
				_etvEdit = 0;
				_timeEdit = 0;
				return SettingsPage2;
			}

		case Down:
			if(_timeEdit <= 0) {
				_timeEdit = 0;
				return Stay;
			}
			if(_timeEdit <= 10) _timeEdit--;
			else _timeEdit -= 5;
			return Stay;

		case Up:
			if(_timeEdit >= 120) {
				_timeEdit = 120;
				return Stay;
			}
			if(_timeEdit < 10) _timeEdit++;
			else _timeEdit += 5;
			return Stay;

		case Confirm:
			_controller.etv.setMinOn(_etvEdit, _timeEdit);
			_controller.memory.saveEtvMinOn(_etvEdit, _timeEdit);
			_etvEdit++;
			_timeEdit = _controller.etv.getMinOn(_etvEdit);
			if(_etvEdit >= _controller.etvNum) {
				_controller.autoCycle.updateTReset();
				return HomePage;
			}
			return Stay;

		default:
			return Stay;
	}
}

void EditEtvTime::show() {
	if(_redraw) {
		_controller.display.printData("Etv", _etvEdit + 1, "per", _timeEdit, "minuti");
		int8_t numDigits = 1 + (_timeEdit >= 10) + (_timeEdit >= 100);
		_controller.display.blinkAt(9 + numDigits, 0);
		_redraw = false;
	}
}
