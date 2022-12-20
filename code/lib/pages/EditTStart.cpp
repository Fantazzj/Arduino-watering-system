#ifndef EDIT_T_START_CPP
#define EDIT_T_START_CPP

#include "Page.cpp"

class EditTStart : public Page {
private:
	MyTime _newTime;
	int8_t _editPhase = 1;

public:
	EditTStart(PageController* controller) :
		Page(controller) {
		_newTime = _controller->autoCycleGetTStart();
	}

	PageNum exec() {
		KeypadButton key = _controller->keypad();

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
					_controller->autoCycleSetTStart(_newTime);
					return HomePage;
				} else return Stay;

			default:
				return Stay;
		}
	}

	void show() {
		if(_redraw) {
			_controller->displayPrint("Orario di avvio", _newTime.hour, ":", _newTime.min, "");
			if(_editPhase == 2) _controller->displayShowCursor(6, 1);
			else _controller->displayShowCursor(1, 1);
			_redraw = false;
		}
	}

protected:
};

#endif
