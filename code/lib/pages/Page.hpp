#ifndef PAGE_CPP
#define PAGE_CPP

#include "PageController.hpp"

enum PageNum : int8_t {
	Stay = 0,
	HomePage,
	SettingsPage1,
	EditClockPage,
	SettingsPage2,
	EditEtvTimePage,
	SettingsPage3,
	ManualEtvPage,
	SettingsPage4,
	EditSRWateredPage,
	SettingsPage5,
	EditTStartPage,
	SettingsPage6,
	EditEtvDaysPage
};

class Page {
private:
public:
	explicit Page(PageController* controller);
	virtual ~Page();
	virtual PageNum exec();
	virtual void show();

protected:
	PageController* _controller;
	bool _redraw = true;
};

#endif
