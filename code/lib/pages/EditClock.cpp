#include "EditClock.hpp"

EditClock::EditClock(PageController* controller) :
	Page(controller) {
	_editPhase = 1;
	_oldTime = controller->clockGetTime();
	_newTime = _oldTime;
}

PageNum EditClock::exec() {
	KeypadButton key = _controller->keypad();

	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			_editPhase--;
			if(_editPhase <= 0) return SettingsPage1;
			return Stay;

		case Down:
			switch(_editPhase) {
				case 1:
					_newTime.date.dow = (_newTime.date.dow > Monday) ? _newTime.date.dow - (Dow)1 : Sunday;
					break;
				case 2:
					_newTime.time.hour = (_newTime.time.hour > 0) ? _newTime.time.hour - 1 : 23;
					break;
				case 3:
					_newTime.time.min = (_newTime.time.min > 0) ? _newTime.time.min - 1 : 59;
					break;
				case 4:
					_newTime.date.day = (_newTime.date.day > 1) ? _newTime.date.day - 1 : 31;
					break;
				case 5:
					_newTime.date.mon = (_newTime.date.mon > 1) ? _newTime.date.mon - 1 : 12;
					break;
				case 6:
					_newTime.date.year = (_newTime.date.year > 2021) ? _newTime.date.year - 1 : 2021;
					break;
			}
			return Stay;

		case Up:
			switch(_editPhase) {
				case 1:
					_newTime.date.dow = (_newTime.date.dow < Sunday) ? _newTime.date.dow + 1 : Monday;
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
				_controller->clockSetTime(_newTime);
				return HomePage;
			} else return Stay;

		default:
			return Stay;
	}
}

void EditClock::show() {
	if(_redraw) {
		_controller->displayPrint(_newTime);
		_redraw = false;

		switch(_editPhase) {
			case 1:
				_controller->displayShowCursor(0, 0);
				break;
			case 2:
				_controller->displayShowCursor(12, 0);
				break;
			case 3:
				_controller->displayShowCursor(15, 0);
				break;
			case 4:
				_controller->displayShowCursor(1, 1);
				break;
			case 5:
				_controller->displayShowCursor(4, 1);
				break;
			case 6:
				_controller->displayShowCursor(9, 1);
				break;
		}
	}
}
