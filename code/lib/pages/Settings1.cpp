#ifndef SETTINGS1_CPP
#define SETTINGS1_CPP

#include "Page.cpp"

class Settings1 : public Page {
private:
public:
	Settings1(PageController* controller) :
		Page(controller) {
		_controller->displayHideCursor();
	}

	PageNum exec() {
		KeypadButton key = _controller->keypad();
		if(key != NoBtn) _redraw = true;
		switch(key) {
			case Cancel:
				return HomePage;
			case Down:
				return SettingsPage6;
			case Up:
				return SettingsPage2;
			case Confirm:
				return EditClockPage;
			default:
				return Stay;
		}
	}

	void show() {
		if(_redraw) {
			_controller->displayPrint((char*)"Cambia data e ora");
			_redraw = false;
		}
	}

protected:
};

#endif
