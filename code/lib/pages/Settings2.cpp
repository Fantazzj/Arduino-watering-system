#ifndef SETTINGS2_CPP
#define SETTINGS2_CPP

#include "Page.cpp"

class Settings2 : public Page {
private:
public:
	Settings2(PageController* controller) :
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
				return SettingsPage1;
			case Up:
				return SettingsPage3;
			case Confirm:
				return EditEtvTimePage;
			default:
				return Stay;
		}
	}

	void show() {
		if(_redraw) {
			_controller->displayPrint("Cambia tempo elettrovalvole");
			_redraw = false;
		}
	}

protected:
};

#endif
