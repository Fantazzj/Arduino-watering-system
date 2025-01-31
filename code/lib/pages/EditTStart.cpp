#include "EditTStart.hpp"

EditTStart::EditTStart(PageController& controller) :
	Page(controller) {
	_newTime = _controller.autoCycle.tStart;
}

PageNum EditTStart::exec() {
	KeypadButton key = _controller.keypadButton();

	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			_editPhase = 1;
			return SettingsPage3;

		case Down:
			switch(_editPhase) {
				case 1:
					_newTime.hour = (_newTime.hour > 0) ? _newTime.hour - 1 : 23;
					break;
				case 2:
					_newTime.min = (_newTime.min > 0) ? _newTime.min - 5 : 55;
					break;
			}
			return Stay;

		case Up:
			switch(_editPhase) {
				case 1:
					_newTime.hour = (_newTime.hour < 23) ? _newTime.hour + 1 : 0;
					break;
				case 2:
					_newTime.min = (_newTime.min < 55) ? _newTime.min + 5 : 0;
					break;
			}
			return Stay;

		case Confirm:
			_editPhase++;
			if(_editPhase == 3) {
				_editPhase = 1;
				_controller.autoCycle.tStart = _newTime;
				_controller.autoCycle.updateTReset();
				_controller.memory.saveStartTime(_newTime);
				return HomePage;
			} else return Stay;

		default:
			return Stay;
	}
}

void EditTStart::show() {
	if(_redraw) {
		_controller.display.printData("Orario di avvio", _newTime.hour, ":", _newTime.min, "");
		if(_editPhase == 2) _controller.display.blinkAt(6, 1);
		else _controller.display.blinkAt(1, 1);
		_redraw = false;
	}
}
