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
				//_controller.debugger.print("Watering start time set to: ");
				//_controller.debugger.println(_newTime);

				_controller.autoCycle.updateTReset();
				_controller.memory.saveStartTime(_newTime);
				return HomePage;
			}
			return Stay;

		default:
			return Stay;
	}
}

void EditTStart::show() {
	if(_redraw) {
		char text[22] = "Orario di avvio";
		text[15] = ' ';
		text[16] = _newTime.hour/10 + '0';
		text[17] = _newTime.hour%10 + '0';
		text[18] = ':';
		text[19] = _newTime.min/10 + '0';
		text[20] = _newTime.min%10 + '0';
		text[21] = '\0';
		_controller.display.printSimpleText(text);
		if(_editPhase == 2) _controller.display.blinkAt(4, 1);
		else _controller.display.blinkAt(1, 1);
		_redraw = false;
	}
}
