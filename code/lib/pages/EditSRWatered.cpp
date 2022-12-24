#ifndef EDIT_SR_WATERED_CPP
#define EDIT_SR_WATERED_CPP

#include "Page.cpp"

class EditSRWatered : public Page {
private:
	bool _watered = false;

public:
	EditSRWatered(PageController* controller) :
		Page(controller) {
		_watered = _controller->autoCycleGetWatered();
	}

	PageNum exec() {
		KeypadButton key = _controller->keypad();

		if(key != NoBtn) _redraw = true;

		switch(key) {
			case Cancel:
				return SettingsPage5;

			case Confirm:
				_controller->autoCycleSetWatered(!_watered);
				return HomePage;

			default:
				return Stay;
		}
	}

	void show() {
		if(_redraw) {
			if(!_watered) _controller->displayPrint((char*)"Imposta gia' innaffiato");
			else _controller->displayPrint((char*)"Imposta da innaffiare");
			_controller->displayShowCursor(15, 1);
			_redraw = false;
		}
	}

protected:
};

#endif
