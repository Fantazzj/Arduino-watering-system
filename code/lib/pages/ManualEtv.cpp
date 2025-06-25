#include "ManualEtv.hpp"

ManualEtv::ManualEtv(PageController& controller) :
	Page(controller) {
	num = 0;
}

PageNum ManualEtv::exec() {
	const KeypadButton key = controller.keypadButton();
	if(key != NoBtn) redraw = true;

	if(controller.autoCycle.etvOn == -1) {
		switch(key) {
			case Cancel:
				num = 0;
				return SettingsPage1;
			case Up:
				num++;
				if(num >= VALVE_NUM) num = 0;
				return Stay;
			case Down:
				num--;
				if(num < 0) num = VALVE_NUM - 1;
				return Stay;
			case Confirm:
				controller.etv.turnOn(num);
				controller.timer.wait(1000);

				controller.mainSwitch.turnOn();
#ifdef DEBUG
				controller.debugger.print("Manually turn on Etv");
				controller.debugger.println(num + 1);
#endif
				controller.autoCycle.etvOn = num;

				return HomePage;
			default:
				return Stay;
		}
	}

	switch(key) {
		case Cancel:
			return SettingsPage1;

		case Confirm:
			controller.mainSwitch.turnOff();
			controller.timer.wait(1000);

			controller.etv.turnOff(controller.autoCycle.etvOn);
#ifdef DEBUG
			controller.debugger.print("Manually turn off Etv");
			controller.debugger.println(controller.autoCycle.etvOn + 1);
#endif
			controller.autoCycle.etvOn = -1;

			controller.autoCycle.watered = true;
			controller.autoCycle.started = false;
			return HomePage;

		default:
			return Stay;
	}
}

void ManualEtv::show() {
	if(redraw) {
		if(controller.autoCycle.etvOn == -1) controller.display.printData("Accendi elettrovalvola", num + 1, "");
		else controller.display.printData("Spegni elettrovalvola", controller.autoCycle.etvOn + 1, "");
		controller.display.blinkAt(15, 1);
		redraw = false;
	}
}
