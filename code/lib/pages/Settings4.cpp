#ifndef SETTINGS4_CPP
#define SETTINGS4_CPP

#include "Page.cpp"

class Settings4 : public Page {
private:
public:
	Settings4(PageController* controller) :
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
				return SettingsPage3;
			case Up:
				return SettingsPage5;
			case Confirm:
				return ManualEtvPage;
			default:
				return Stay;
		}
	}

	void show() {
		if(_redraw) {
			_controller->displayPrint((char*)"Impostazione manuale");
			_redraw = false;
		}
	}

protected:
};

#endif
