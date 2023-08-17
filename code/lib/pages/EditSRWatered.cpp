#include "EditSRWatered.hpp"

EditSRWatered::EditSRWatered(PageController* controller) :
	Page(controller) {
	_watered = _controller->autoCycleGetWatered();
}

PageNum EditSRWatered::exec() {
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

void EditSRWatered::show() {
	if(_redraw) {
		if(!_watered) _controller->displayPrint((char*) "Imposta gia' innaffiato");
		else _controller->displayPrint((char*) "Imposta da innaffiare");
		_controller->displayShowCursor(15, 1);
		_redraw = false;
	}
}
