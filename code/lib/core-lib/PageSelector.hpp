#ifndef PAGE_SELECTOR_HPP
#define PAGE_SELECTOR_HPP

#include "AutoCycle.hpp"

#include "../pages/Home.hpp"
#include "../pages/Page.hpp"
#include "../pages/PageController.hpp"

#include "../pages/EditClock.hpp"
#include "../pages/Settings1.hpp"

#include "../pages/EditEtvTime.hpp"
#include "../pages/Settings2.hpp"

#include "../pages/EditTStart.hpp"
#include "../pages/Settings3.hpp"

#include "../pages/ManualEtv.hpp"
#include "../pages/Settings4.hpp"

#include "../pages/EditSRWatered.hpp"
#include "../pages/Settings5.hpp"

#include "../pages/EditEtvDays.hpp"
#include "../pages/Settings6.hpp"

class PageSelector {
private:
	static constexpr int8_t DISPLAY_BACKLIGHT_MIN_ON = 2;
	PageController controller;
	Page* activePage;
	PageNum newPage = Stay;
	MyTime backlightTurnOnTime;

public:
	explicit PageSelector(Keypad& myKeypad, UnitDisplay& myDisplay, Clock& myClock, ValveGroupN& myEtv, MainSwitch& _myMainSwitch, Memory& myMemory, Timer& myTimer, Debugger& myDebugger, AutoCycle& autoCycle);
	void begin();
	void exec();
	void show();

protected:
};

#endif//PAGE_SELECTOR_HPP
