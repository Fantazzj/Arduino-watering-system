#ifndef EDIT_CLOCK_PAGE_CPP
#define EDIT_CLOCK_PAGE_CPP

#include "Page.hpp"
#include "PageController.hpp"

class EditClock : public Page {
private:
	MyTime _newTime;
	MyTime _oldTime;
	int8_t _editPhase = 1;

public:
	EditClock(PageController* controller);
	PageNum exec();
	void show();

protected:
};

#endif//EDIT_CLOCK_PAGE_CPP
