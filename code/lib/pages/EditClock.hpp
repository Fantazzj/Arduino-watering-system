#ifndef EDIT_CLOCK_PAGE_CPP
#define EDIT_CLOCK_PAGE_CPP

#include "Page.hpp"
#include "PageController.hpp"

class EditClock : public Page {
private:
	MyDateTime _newTime;
	int8_t _editPhase = 1;

public:
	EditClock(PageController* controller);
	PageNum exec() override;
	void show() override;

protected:
};

#endif//EDIT_CLOCK_PAGE_CPP
