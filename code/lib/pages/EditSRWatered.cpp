#include "EditSRWatered.hpp"

EditSRWatered::EditSRWatered(PageController& controller) :
	Page(controller) {
	_watered = _controller.autoCycle.watered;
}

PageNum EditSRWatered::exec() {
	KeypadButton key = _controller.keypadButton();

	if(key != NoBtn) _redraw = true;

	switch(key) {
		case Cancel:
			return SettingsPage5;

		case Confirm:
			_controller.autoCycle.watered = !_watered;
			//if(_watered)
			//	_controller.debugger.println("Reset watered state");
			//else
			//	_controller.debugger.println("Set watered state");
			return HomePage;

		default:
			return Stay;
	}
}

void EditSRWatered::show() {
	if(_redraw) {
		if(!_watered) _controller.display.printSimpleText("Imposta gia' innaffiato");
		else _controller.display.printSimpleText("Imposta da innaffiare");
		_controller.display.blinkAt(15, 1);
		_redraw = false;
	}
}
