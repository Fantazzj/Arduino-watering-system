#ifndef EDIT_ETV_DAYS_CPP
#define EDIT_ETV_DAYS_CPP

#include "Page.cpp"

class EditEtvDays : public Page {
private:
	int8_t _etvEdit = 1;
	int8_t _daysEdit = _controller->getEtvDays(1);

public:
	EditEtvDays(PageController* controller) :
		Page(controller) {
		_etvEdit = 1;
		_daysEdit = _controller->getEtvDays(1);
	}

	PageNum exec() {
		KeypadButton key = _controller->keypad();
		if(key != NoBtn) _redraw = true;

		switch(key) {
			case Cancel:
				if(_etvEdit >= 2) {
					_etvEdit--;
					_daysEdit = _controller->getEtvDays(_etvEdit);
					return Stay;
				} else {
					_etvEdit = 1;
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
				_controller->setEtvDays(_etvEdit++, _daysEdit);
				_daysEdit = _controller->getEtvDays(_etvEdit);
				if(_etvEdit > _controller->getEtvNum())
					return HomePage;
				else return Stay;
		}
	}

	void show() {
		if(_redraw) {
			_controller->displayPrint((char*)"Etv", _etvEdit, (char*)"ogni", _daysEdit, (char*)"giorni");
			_controller->displayShowCursor(11, 0);
			_redraw = false;
		}
	}

protected:
};

#endif
