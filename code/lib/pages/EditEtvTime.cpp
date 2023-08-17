#include "EditEtvTime.hpp"

EditEtvTime::EditEtvTime(PageController* controller) :
	Page(controller) {
	_etvEdit = 1;
	_timeEdit = _controller->getEtvMinOn(1);
}

PageNum EditEtvTime::exec() {
	KeypadButton key = _controller->keypad();
	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			if(_etvEdit >= 2) {
				_etvEdit--;
				_timeEdit = _controller->getEtvMinOn(_etvEdit);
				return Stay;
			} else {
				_etvEdit = 1;
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
			_controller->setEtvMinOn(_etvEdit++, _timeEdit);
			_timeEdit = _controller->getEtvMinOn(_etvEdit);
			if(_etvEdit > _controller->getEtvNum())
				return HomePage;
			else return Stay;

		default:
			return Stay;
	}
}

void EditEtvTime::show() {
	if(_redraw) {
		_controller->displayPrint((char*) "Etv", _etvEdit, (char*) "per", _timeEdit, (char*) "minuti");
		_controller->displayShowCursor(10, 0);
		_redraw = false;
	}
}
