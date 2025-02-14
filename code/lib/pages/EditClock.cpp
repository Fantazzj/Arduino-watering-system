#include "EditClock.hpp"

EditClock::EditClock(PageController& controller) :
	Page(controller) {
	_editPhase = 1;
	_newTime = controller.clock.getDateTime();
}

PageNum EditClock::exec() {
	KeypadButton key = _controller.keypadButton();

	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			_editPhase--;
			if(_editPhase <= 0) return SettingsPage1;
			return Stay;

		case Down:
			switch(_editPhase) {
				case 1:
					_newTime.date.dow = (_newTime.date.dow > Sunday) ? _newTime.date.dow - 1u : Saturday;
					break;
				case 2:
					_newTime.time.hour = (_newTime.time.hour > 0) ? _newTime.time.hour - 1u : 23u;
					break;
				case 3:
					_newTime.time.min = (_newTime.time.min > 0) ? _newTime.time.min - 1u : 59u;
					break;
				case 4:
					_newTime.date.day = (_newTime.date.day > 1) ? _newTime.date.day - 1u : 31u;
					break;
				case 5:
					_newTime.date.mon = (_newTime.date.mon > 1) ? _newTime.date.mon - 1u : 12u;
					break;
				case 6:
					_newTime.date.year = (_newTime.date.year > 2021) ? _newTime.date.year - 1u : 2021u;
					break;
			}
			return Stay;

		case Up:
			switch(_editPhase) {
				case 1:
					_newTime.date.dow = (_newTime.date.dow < Saturday) ? _newTime.date.dow + 1 : Sunday;
					break;
				case 2:
					_newTime.time.hour = (_newTime.time.hour < 23) ? _newTime.time.hour + 1 : 0;
					break;
				case 3:
					_newTime.time.min = (_newTime.time.min < 59) ? _newTime.time.min + 1 : 0;
					break;
				case 4:
					_newTime.date.day = (_newTime.date.day < 31) ? _newTime.date.day + 1 : 1;
					break;
				case 5:
					_newTime.date.mon = (_newTime.date.mon < 12) ? _newTime.date.mon + 1 : 1;
					break;
				case 6:
					_newTime.date.year++;
					break;
			}
			return Stay;

		case Confirm:
			_editPhase++;
			if(_editPhase > 6) {
				_controller.clock.setDateTime(_newTime);
				_controller.debugger.print("Date and Time updated: ");
				_controller.debugger.println(_newTime);
				_controller.timeToEdit = false;
				return HomePage;
			}
			return Stay;

		default:
			return Stay;
	}
}

void EditClock::show() {
	if(_redraw) {
		_controller.display.showClock(_newTime);
		_redraw = false;

		switch(_editPhase) {
			case 1:
				_controller.display.blinkAt(0, 0);
				break;
			case 2:
				_controller.display.blinkAt(12, 0);
				break;
			case 3:
				_controller.display.blinkAt(15, 0);
				break;
			case 4:
				_controller.display.blinkAt(1, 1);
				break;
			case 5:
				_controller.display.blinkAt(4, 1);
				break;
			case 6:
				_controller.display.blinkAt(9, 1);
				break;
		}
	}
}
